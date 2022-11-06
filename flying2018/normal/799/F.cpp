#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define ll long long
#define N 200010
#define ull unsigned long long
#define fi first
#define se second
#define MP make_pair
#define P pair<ll,ll>
using namespace std;
ull b=1;
void nxt(){b^=b>>13;b^=b<<15;b^=b>>17;b^=19260817;}
ull bs[N];
int c[N],t[N];
map<ull,P >mp;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++,nxt())
    {
        int l,r;
        scanf("%d%d",&l,&r);
        bs[l+1]^=b,bs[r+1]^=b;
        t[l]++,t[r+1]--;
    }
    for(int i=1;i<=m;i++) bs[i]^=bs[i-1];
    for(int i=1;i<=m;i++) bs[i]^=bs[i-1];
    for(int i=1;i<=m;i++) t[i]+=t[i-1];
    long long ans=0;
    for(int i=1;i<=m;i++)
    {
        P &a=mp[bs[i]];a.fi++,a.se+=i-1;
        ans+=a.fi*i-a.se;
    }
    for(int i=1;i<=m;i++) c[i]=t[i]?0:(c[i-1]+1);
    for(int i=1;i<=m;i++) ans-=1ll*c[i]*(c[i]+1)/2;
    printf("%lld\n",ans);
    return 0;
}