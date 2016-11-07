#include<iostream>

using namespace std;

int getLongestUnRepeatedSubStr(const string &str){
    int hashTable[256]={0};
    int start=0;
    int mstart=0;
    int mlen=0;
    int idx=0;
    int len=0;
    while(idx!=str.size()){
        if(hashTable[str[idx]]==1){
            if(len>mlen){
                mstart=start;
                mlen=len;
            }
            while(str[start]!=str[idx]){
                hashTable[str[start]]=0;
                start++;
                len--;
            }
            start++;
        }
        else{
            hashTable[str[idx]]=1;
            len++;
        }
        idx++;
    }

    if(len>mlen){
        mlen=len;
        mstart=start;
    }

    cout<< str.substr(mstart,mlen) <<endl;
    return mlen;
}

int main(){
    string str;
    while(cin>>str){
        cout << getLongestUnRepeatedSubStr(str) << endl;
    }
    return 0;
}
