#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 100010
#define inf 1e17
#define ll long long
using namespace std;
struct ton{
    #define MX 1919810
    #define P pair<ll,ll>
    #define MP make_pair
    #define fi first
    #define se second
    vector<P >v[MX+3];
    ll& operator ()(ll a,int b,int c,int d)
    {
        a=((a*4000ll+b)*4000ll+c)*3ll+(d==1);
        int k=a%MX;
        for(auto u=v[k].begin();u!=v[k].end();u++)
        if(u->fi==a) return u->se;
        v[k].push_back(MP(a,-inf));
        return v[k].back().se;
    }
}f;
ll s[N];
ll F(int l,int r,int k,int p)
{
    if(r-l+1<k) return 0;
    if(r-l+1==k) return p*(s[r]-s[l-1]);
    ll &u=f(l,r,k,p);
    if(u!=-inf) return u;
    if(p==-1) u=min(F(l,r-k,k,1)-(s[r]-s[r-k]),F(l,r-k-1,k+1,1)-(s[r]-s[r-k-1]));
    else u=max(F(l+k,r,k,-1)+(s[l+k-1]-s[l-1]),F(l+k+1,r,k+1,-1)+(s[l+k]-s[l-1]));
    return u;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&s[i]),s[i]+=s[i-1];
    printf("%lld\n",F(1,n,1,1));
    return 0;
}