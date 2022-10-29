#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
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
const ll INF = 1e18;
const ld E = 1e-12;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, kl=0, sz=0, a[1000001], b[1000001];
vector<ll> v[1000001];

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
    cin >> n;
    for (int i = 1; i <= n; i++) b[i]=-1;
    a[0]=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i]!=a[i-1])
        {
            for (int j = a[i-1]+1; j <= a[i]-1; j++) v[i].pb(j);
            b[i]=a[i-1];
        }
    }
    vector<ll> w;
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < v[i].size(); j++) w.pb(v[i][j]);
        if (b[i]!=-1) continue;
        if (w.size()==0) b[i]=n+1; else
            b[i]=w.back(), w.pop_back();
    }
    if (w.size()) cout << "-1\n"; else
    {
        for (int i = 1; i <= n; i++) cout << b[i] << " ";
    }
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
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
3 10 12
1 Fufel 1 WA 1
2 OSUTeam 1 WA 2
3 vitebsk02 3 OK
5 fufel 3 WA 2
6 fufel 3 CE
6 fufel 3 TL 78
19 fufel 3 OK
23 fufel 1 OK
45 balukTeam 2 OK
54 VitebskieKovry 1 OK
74 MORGENSHTEND 2 WA 3
9595 ShlutLandShlutLand 1 OK
*/