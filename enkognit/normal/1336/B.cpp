#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, d, h, TT, T, L, n1, n2, n3, R, mx=0, ans;
vector<ll> v;
bool tt[1000001];

ll binpow(ll h, ll r, ll md = MOD)
{

    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}



void solve()
{
    vector<ll> n(3);
    cin >> n[0] >> n[1] >> n[2];
    vector<vector<ll> > a;
    a.resize(3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n[i]; j++)
        {
            ll x;
            cin >> x;
            a[i].pb(x);
        }
        sort(all(a[i]));
    }
    ll ans=5e18;
    vector<ll> v;
    v.pb(0);
    v.pb(1);
    v.pb(2);
    do
    {
        for (int i = 0; i < a[v[0]].size(); i++)
        {
            if (a[v[1]][0]>a[v[0]][i]) continue;
            if (a[v[2]].back()<a[v[0]][i]) continue;
            ll j=upper_bound(all(a[v[1]]), a[v[0]][i])-a[v[1]].begin()-1;
            ll u=upper_bound(all(a[v[2]]), a[v[0]][i]-1)-a[v[2]].begin();
            //cout << " " << a[v[1]][j] << " " << a[v[0]][i] << " " << a[v[2]][u] << "\n";
            ans=min(ans, sqr(a[v[0]][i]-a[v[1]][j])+sqr(a[v[0]][i]-a[v[2]][u])+sqr(a[v[1]][j]-a[v[2]][u]));
        }
    }while(next_permutation(all(v)));
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
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
2
3 2
10
01
01
DL
RU
UU
2 4
1111
0101
RDRD
UUUU
*/