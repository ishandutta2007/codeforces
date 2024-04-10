#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define do_anal exit(0)

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll md = 11234549;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, ans=1, N, mx[200001];
vector<ll> c[200001];

ll binpow(ll h, ll r, ll md)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    return l;
}

void dfs(int h,int p=-1)
{
    if (h!=1 && c[h].size()==1)
    {
        //cout << "  " << h << " " << mx[h] << "\n";
        mx[h]=0;
        return;
    } else mx[h]=1e18;
    pll o=mp(0, 0);
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs(c[h][i], h);
            if (!T) return;
            mx[h]=min(mx[h],mx[c[h][i]]+1);
            if (mx[c[h][i]]+1>o.fi) swap(o.fi,o.se), o.fi=mx[c[h][i]]+1; else
            if (mx[c[h][i]]+1>o.se) o.se=mx[c[h][i]]+1;
        }
    if (o.se>0)
    {
        if (o.fi+1>N)
        {
            if (o.fi>N) {T=0;return;} else
            if (o.se+1>N) {T=0;return;} else mx[h]=o.fi;
        }
    }
    if (h==1 && mx[h]>N)
    {
        T=0;
        return;
    }
    //cout << "  " << h << " " << mx[h] << " " << o.fi << " " << o.se << "\n";
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) mx[i]=0, c[i].clear();
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    ll l=1, r=n;
    while (l<r)
    {
        int w=(l+r)/2;
        T=1;
        N=w;
        //cout << " " << w << "\n";
        dfs(1);
        if (T) r=w; else l=w+1;
    }
    cout << l << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
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
9 0
1 1
3 1
5 1
5 2
3 2
3 3
2 3
2 2
1 2
*/