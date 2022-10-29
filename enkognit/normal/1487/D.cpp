#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, T, a[300005];
vector<ll> v;

ll gcd(ll x, ll y)
{
    while (x && y)
    {
        if (x<y) swap(x,y);
        x%=y;
    }
    //cout << x+y << "\n";
    return x+y;
}

void solve()
{
    cin >> n;
    ll l=0, r=v.size()-1;
    while (l<r)
    {
        ll w=(l+r+1)/2;
        if (v[w]>n) r=w-1; else l=w;
    }
    cout << l << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    v.pb(0);
    cin >> t;
    n=1e9;
    ll l=0, r=n;
    while (l<r)
    {
        ll w=(l+r+1)/2;
        if ((w*w-1)/2>n) r=w-1; else
        if (w*w+sqr((w*w-1)/2)<=n*n) l=w; else r=w-1;
    }
    ll ans=0;
    for (ll i = 2; i <= l; i++)
        if (i%2)
        {
            ll a=i, b=(i*i-1)/2;
            ll p=a*a+b*b, u=sqrt(p);
            if (u*u==p && u<=n)
            {
                ans++;
                v.pb(u);
            }
        }
    while (t--)
    {
        solve();
    }
    return 0;
}
/*

10
4 1 7 6 5 5 4 2 3 1
*/