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

const ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-8;
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 29, p3 = 7, p4=rnd()%100+1, md1 = MOD, md2 = 998244353, md3=998244357, md4=rnd()%1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, ans, tt[300001], kl[300001], k1=0, k0=0, dp[3000001];
pll d[300001];
vector<ll> c[300001];
ll a[300001];

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

void dfs(int h,int p=-1)
{
    if (tt[h]==1) d[h].fi++;
    if (tt[h]==2) d[h].se++;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            a[c[h][i]]=min(a[c[h][i]],a[h]);
            dfs(c[h][i], h);
            d[h].fi+=d[c[h][i]].fi;
            d[h].se+=d[c[h][i]].se;
        }
    ll pp=min(d[h].fi,d[h].se);
    //cout << h << " " << d[h].fi << " " << d[h].se << " " << a[h] << " " << pp << "\n";
    ans+=pp*a[h]*2;
    d[h].fi-=pp;
    d[h].se-=pp;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        a[i]=x;
        if (y!=z)
        {
            if (y==1) tt[i]=1; else tt[i]=2;
        }
    }
    for (int i = 1 ;i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    dfs(1);
    if (d[1].fi!=0 || d[1].se!=0) {cout << "-1\n";return 0;}
    cout << ans << "\n";
    return 0;
}

/*
4
1 4 3 6
3
1 2 3
4
6 3 4 1
*/