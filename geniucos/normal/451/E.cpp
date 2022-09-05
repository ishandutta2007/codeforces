#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int Nr,sol,mod,n,i,j,nrb[(1<<20)+2],inv[50];
long long nS,S,A[50],a[50];
int pow(int a,int b)
{
    int i,p=1;
    for(i=0;(1<<i)<=b;i++)
    {
        if(b&(1<<i)) p=(1LL*p*a)%mod;
        a=(1LL*a*a)%mod;
    }
    return p;
}
int comb(long long N,int K)
{
    long long i;
    int p=1;
    for(i=N;i>=N-K+1;i--)
        p=(1LL*p*(i%mod))%mod;
    for(i=1;i<=K;i++)
        p=(1LL*p*inv[i])%mod;
    return p;
}
int howmany(long long S,int Nr)
{
    if(S<0) return 0;
    return comb(S+Nr-1,Nr-1);
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
mod=1000000007;
scanf("%d",&n);
scanf("%I64d",&S);
for(i=1;i<=n;i++)
    scanf("%I64d",&a[i]);
for(i=1;i<n;i++)
    inv[i]=pow(i,mod-2);
for(i=1;i<=n;i++)
    a[i]++;
sol=howmany(S,n);
for(i=1;i<(1<<n);i++)
{
    if(i&1) nrb[i]=nrb[i>>1]+1;
    else nrb[i]=nrb[i>>1];
    nS=S;
    for(j=0;j<n;j++)
        if(i&(1<<j)) nS-=a[j+1];
    Nr=howmany(nS,n);
    if(nrb[i]&1)
    {
        sol-=Nr;
        if(sol<0) sol+=mod;
    }
    else
    {
        sol+=Nr;
        if(sol>=mod) sol-=mod;
    }
}
printf("%d\n",sol);
return 0;
}