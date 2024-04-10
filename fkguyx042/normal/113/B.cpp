#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN = 2005;
char s[MAXN],s1[MAXN],s2[MAXN];
int ch[MAXN*1000][26];
int sz;
int n1,n2;
int ans;
int L[MAXN],R[MAXN];

void call(char *s,int n,int l){
    int f=0;
    for(int i=0;i<n;i++){
        if(ch[f][s[i]-'a']==0){
            ch[f][s[i]-'a']=++sz;
            if(i>=n2-1 && R[l+i] && i>=n1-1){
            ans++;
            }
        }
        f=ch[f][s[i]-'a'];
    }
}

int main()
{
    scanf("%s",s);
    scanf("%s",s1);
    scanf("%s",s2);
    int n=strlen(s);
    n1=strlen(s1);
    n2=strlen(s2);
    for(int i=0;i<n;i++){
        L[i]=R[i]=1;
        int res=0;
        for(int j=i;j<n && j-i<n1;j++){
            if(s[j]!=s1[j-i]){
                L[i]=0;
                break;
            }
            res++;
        }
        if(res!=n1)L[i]=0;
        res=0;
        for(int j=i;j>=0 && i-j<n2;j--){
            if(s[j]!=s2[n2-(i-j)-1]){
                R[i]=0;
                break;
            }
            res++;
        }
        if(res!=n2)R[i]=0;
    }
    for(int i=0;i<n;i++){
        if(L[i]==0)continue;
        call(s+i,n-i,i);
    }
    printf("%d\n",ans);
    return 0;
}