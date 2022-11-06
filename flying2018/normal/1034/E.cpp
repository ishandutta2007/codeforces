#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define N 3000010
using namespace std;
ll f[N],g[N];
void fwt(ll f[],int n,int opt)
{
    for(int i=1;i<n;i<<=1)
        for(int j=0;j<n;j+=i<<1)
            for(int k=0;k<i;k++) f[i+j+k]+=opt*f[j+k];
}
char s1[N],s2[N];
int main()
{
    int n;
    scanf("%d%s%s",&n,s1,s2);
    n=1<<n;
    for(int i=0;i<n;i++) f[i]=(s1[i]-'0')*1ll<<(__builtin_popcount(i)<<1);
    for(int i=0;i<n;i++) g[i]=(s2[i]-'0')*1ll<<(__builtin_popcount(i)<<1);
    fwt(f,n,1),fwt(g,n,1);
    for(int i=0;i<n;i++) f[i]=f[i]*g[i];
    fwt(f,n,-1);
    for(int i=0;i<n;i++) putchar('0'+((f[i]>>(__builtin_popcount(i)<<1))&3));
    return 0;
}