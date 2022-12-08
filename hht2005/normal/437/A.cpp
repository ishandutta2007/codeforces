#include<bits/stdc++.h>
using namespace std;
char s[210];
int len[4];
int main() {
    int ans=-1;
    for(int i=0;i<4;i++) {
        cin>>s;
        len[i]=strlen(s)-2;
        
    }
    for(int i=0;i<4;i++) {
        int s1=0,s2=0;
        for(int j=0;j<4;j++)
            if(i!=j) {
                if(len[i]>=2*len[j])s1++;
                if(len[j]>=2*len[i])s2++;
            }
        if(s1==3||s2==3) {
            if(ans==-1)ans=i;//
            else ans=2;//
        }//
    }//
    if(ans==-1)ans=2;//
    putchar('A'+ans);
    putchar('\n');
    return 0;
}