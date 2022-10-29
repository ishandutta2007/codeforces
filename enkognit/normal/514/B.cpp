#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
const ll INF=1e18;
const ld E=1e-8;
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 29, md1 = MOD, md2 = 998244353;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, q, a[200001];
bool tt[200001];

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

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll x0, y0;
    vector<pll> v;
    cin >> n >> x0 >> y0;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        x-=x0;
        y-=y0;
        v.pb(mp(x,y));
    }
    ll ans=0;
    for (int i = 0; i < n; i++) a[i]=i;
    for (int i = 0; i < v.size(); i++)
        for (int j = i+1; j < v.size(); j++)
            if (v[i].fi*v[j].se==v[i].se*v[j].fi)
            {
                ll x=min(a[i],a[j]);
                a[i]=x;
                a[j]=x;
            }
    for (int i = 0; i < n; i++)
        if (!tt[a[i]]) ans++, tt[a[i]]=1;
    cout << ans << "\n";
    return 0;
}

/*
7 6
2 1 1
3 1 2
1 4 0
4 5 1
5 6 3
5 7 4
1 3
4 1
2 4
2 5
3 5
3 7
*/