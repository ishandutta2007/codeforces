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
ll a,b,c,d;
inline ll calc2(ll x)
{
    return x*(x-1)/2*d*b;
}
inline ll calc(ll x)
{
    ll xp=min(x,c/d+1);
    ll xq=x-xp;
    return a*x-(xq*b*c+calc2(xp));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        cin>>a>>b>>c>>d;
        if(a>b*c)
        {
            cout<<"-1\n";
            continue;
        }
        ll s=1,e=1000000;
        while(s+3<e)
        {
            ll m1=(s*2+e+1)/3;
            ll m2=(s+e*2+2)/3;
            if(calc(m1)<calc(m2))
                s=m1+1;
            else
                e=m2-1;
        }
        ll mh=a;
        for(ll i=s;i<=e;i++)
            mh=max(mh,calc(i));
        cout<<mh<<'\n';
    }
    return 0;
}