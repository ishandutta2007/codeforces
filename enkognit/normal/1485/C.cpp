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

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

ll n, m, k;

ll get(ll h)
{
    return h*(h+1)/2;
}

void solve()
{
    ll x, y;
    cin >> x >> y;
    y=min(y, x-1);
    ll o=y+1;
    vector<pll> v;
    v.pb(mp(o, x/o));
    while (v.back().fi>2)
    {
        //cout << v.back().fi << " " << v.back().se << "\n";
        ll z=v.back().se+1, p=x/z;
        //cout << p << " " << x/p << "\n";
        v.pb(mp(p, x/p));
    }
    //v.pb(mp(0, 0));
    v.back().fi=2;
    ll ans=0;
    for (int i = 0; i < v.size()-1; i++)
    {
        //cout << v[i].fi << " " << v[i+1].fi << " " << v[i].se << "\n";
        //cout << min(v[i].fi,max(v[i+1].fi,v[i].se))-(v[i+1].fi) << "\n";
        ll o=ans;
        ans+=max((v[i].fi-2-max(v[i+1].fi-2,v[i].se)),0ll)*v[i].se;
        if (v[i+1].fi-2<v[i].se) ans+=get(min(v[i].fi-2,v[i].se))-get(v[i+1].fi-2);
        //cout << ans-o << "\n";
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
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