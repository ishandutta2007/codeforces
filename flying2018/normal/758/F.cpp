#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define N 100010
using namespace std;
ll ksm(ll a,ll b)
{
    ll r=1;
    for(;b;b>>=1)
    {
        if(b&1) r=r*a;
        a=a*a;
        if(r>1e8) return 1e8;
    }
    return r;
}
int pw[N];
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
    int n,l,r;
    scanf("%d%d%d",&n,&l,&r);
    if(n>26){puts("0");return 0;}
    if(n==1){printf("%d\n",r-l+1);return 0;}
    if(n==2){printf("%lld\n",1ll*(r-l+1)*(r-l));return 0;}
    for(int i=1;(pw[i]=ksm(i,n-1))<=r;i++);
    long long ans=0;
    for(int i=1;pw[i]<=r;i++)
        for(int j=1;pw[j]<=r;j++)
        if(gcd(i,j)==1 && (i!=1 || j!=1))
        ans+=max(0,min(r/pw[i],r/pw[j])-max((l+pw[i]-1)/pw[i],(l+pw[j]-1)/pw[j])+1);
    printf("%lld",ans);
    return 0;
}