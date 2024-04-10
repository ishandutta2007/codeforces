#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
#include<functional>  
#include<cmath>  
#include<cctype>  
using namespace std; 
#define For(i,n) for(int i=1;i<=n;i++)  
#define Rep(i,n) for(int i=0;i<n;i++)  
#define Fork(i,k,n) for(int i=k;i<=n;i++)  
#define ForD(i,n) for(int i=n;i;i--)  
#define Forp(x) for(int p=pre[x];p;p=next[p])  
#define RepD(i,n) for(int i=n;i>=0;i--)  
#define MEM(a) memset(a,0,sizeof(a))  
#define MEMI(a) memset(a,127,sizeof(a))  
#define MEMi(a) memset(a,128,sizeof(a))  
#define MAXN (50000+10)  
char s[MAXN]; 
int main() 
{ 
    int t=1; 
    while (t--) 
    { 
    int n=strlen(gets(s+1)); 
    For(len,n/2) 
    { 
        int tot=0; 
        For(j,n-len) 
        { 
            if (s[j]==s[j+len]) tot++;else tot=0; 
            if (tot==len) 
            { 
                Fork(k,j+1,n-len) s[k]=s[k+len]; 
                n-=len;len=0;break; 
            } 
        }            
    } 
    s[n+1]=0; 
    puts(s+1); 
    } 
    return 0; 
}