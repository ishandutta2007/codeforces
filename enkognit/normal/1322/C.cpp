#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
/*
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-avx2")
*/
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD=1e9+7;
ll md1=MOD, md2=988244353, p1=621983, p2=751921;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, l, r, cc[500001], lst[1000001];
pll hs[500001];
map<pair<int,int>, int> ww;

ll gcd(int x,int y)
{
    if (x==0 || y==0) return x+y; else return __gcd(x,y);
}

void solve()
{
    cin >> n >> m;
    ww.clear();
    for (int i = 1; i <= n; i++) {cin >> cc[i];hs[i]=mp(0,0);lst[i]=0;}
    vector<pll> v;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.pb(mp(x,y));
    }
    sort(all(v));

    for (int i = 0; i < v.size(); i++)
    {
        ll x=v[i].fi, y=v[i].se;
       // cout << x << " - " << y << "\n";
        if (lst[y]!=x)
        hs[y]=mp((hs[y].fi*p1+x)%md1,(hs[y].se*p2+x)%md2), lst[y]=x;
    }
    ll ans=0;
    vector<ll> z;

    for (int i = 1; i <= n; i++)
    {
        if (hs[i].fi==0 && hs[i].se==0) continue;

        //cout << hs[i].fi << " : " << hs[i].se << "\n";
        if (!ww[hs[i]]) ww[hs[i]]=z.size()+1, z.pb(cc[i]); else z[ww[hs[i]]-1]+=cc[i];
    }
    for (int i = 0; i < z.size(); i++) {ans=gcd(ans,z[i]);}
    //8cout << "\n";
    cout << ans << "\n";
    //cout << "-------------\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
6 7
1 2
1 3
4 5
4 6
1 4
2 5
3 6

6 9
1 2
2 3
3 1
4 5
4 6
6 5
1 4
2 5
3 6
*/