#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000010
using namespace std;
int nxt[N];
char s[N];
int main()
{
    int n,k;
    scanf("%d%d%s",&n,&k,s+1);
    int p=0;
    for(int i=2;i<=n;i++)
    {
        for(;p && s[p+1]!=s[i];p=nxt[p]);
        nxt[i]=(p+=s[p+1]==s[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int u=i-nxt[i],v=i/u;
        if(i%u) putchar('0'+((v/k-v%k)>0));
        else putchar('0'+((v/k-v%k)>=0));
    }
    return 0;
}