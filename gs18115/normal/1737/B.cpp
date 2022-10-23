#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
ll f1(ll x)
{
    ll l=0,r=inf;
    while(l<r)
    {
        ll m=l+(r-l+1)/2;
        if(m*m<=x)
            l=m;
        else
            r=m-1;
    }
    return l;
}
ll f2(ll x)
{
    ll l=0,r=inf;
    while(l<r)
    {
        ll m=l+(r-l+1)/2;
        if(m*m+m<=x)
            l=m;
        else
            r=m-1;
    }
    return l;
}
ll f3(ll x)
{
    ll l=0,r=inf;
    while(l<r)
    {
        ll m=l+(r-l+1)/2;
        if(m*m+m*2<=x)
            l=m;
        else
            r=m-1;
    }
    return l;
}
ll f(ll x)
{
    return f1(x)+f2(x)+f3(x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        ll l,r;
        cin>>l>>r;
        cout<<f(r)-f(l-1)<<'\n';
    }
    return 0;
}