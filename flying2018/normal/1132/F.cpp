#include<iostream>
#include<cstdio>
#include<cstring>
#define N 510
#define inf 1e7
using namespace std;
int f[N][N];
char s[N];
int F(int l,int r)
{
    if(l==r) return 0;
    if(~f[l][r]) return f[l][r];
    f[l][r]=inf;
    for(int k=l;k<=r;k++)
    f[l][r]=min(f[l][r],F(l,k-1)+F(k,r)+(s[l]!=s[k]));
    return f[l][r];
}
int main()
{
    int n;
    scanf("%d%s",&n,s+1);
    memset(f,-1,sizeof(f));
    printf("%d\n",F(0,n));
    return 0;
}