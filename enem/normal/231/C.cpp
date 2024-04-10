#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
//#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rev(i,b,a) for (ll i = b - 1; i >= a; i--)
#define all(v) v.begin(), v.end()
#define maxe(v) *max_element(v.begin(), v.end())
#define mine(v) *min_element(v.begin(), v.end())
#define pb push_back
#define pf push_front
#define rem 1000000007
//#define rem 998244353
#define cont continue
#define debug(n1) cout<<"debug... "<<n1<<"\n"
const ll INF=(1ll<<60)-1;//ll ans = 3e18 + 5;
#define MAXN   10000001
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc=1;
    //cin>>tc;
    while(tc--)
    { 
        ll n,k;
        cin>>n>>k;
        ll a[n];
        rep(i,0,n)cin>>a[i];
        sort(a,a+n);
        ll pre[n];
        pre[0]=a[0];
        rep(i,1,n)
        pre[i]=pre[i-1]+a[i];
        ll cnt=1;
        ll ans=a[0];
        ll ansv=1;
        rep(i,1,n)
        {
            ll l=0;
            ll r=i+2;
            while( l < r )
            {
                ll mid=(l+r)/2;
                if(mid*a[i] - (pre[i]-(i-mid>=0?pre[i-mid]:0)) > k )
                {
                    r=mid;
                }
                else
                {
                    l=mid+1;
                }
            }
            if(l-1>ansv)
            {
                ansv=l-1;
                ans=a[i];
            }
        }
        cout<<ansv<<' '<<ans;
       // cout<< cnt << ' ' << ans ;
    }
}