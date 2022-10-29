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

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, a[200001], mx[200001], sm[200001], kl[200001], kol=1;
vector<ll> c[200001];

ll binpow(ll h, ll r, ll md = MOD)
{
    bool t = 0;
    if (h < 0) t = 1, h = -h;
    if (r % 2 == 0) t = 0;
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    if (t) l = -l;
    //cout << l << "\n";
    return l;
}


void dfs(int h,int p=-1)
{
    if (c[h].size()==0)
    {
        kl[h]=1, mx[h]=a[h], sm[h]=0;
        return;
    }
    //cout << h << "\n";
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs(c[h][i], h);
            mx[h]=max(mx[h], mx[c[h][i]]);
        }
    ll z=0;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            kl[h]+=kl[c[h][i]];
            z+=sm[c[h][i]]+(mx[h]-mx[c[h][i]])*kl[c[h][i]];
        }
    ll o=a[h];
    //cout << h << " " << z << " " << o << "\n";
    if (z<=o)
    {
        o-=z;
        z=0;
    }else z-=o, o=0;
    sm[h]=z;
    //cout << mx[h] << "\n";
    if (o>0)
    {
        mx[h]+=o/kl[h];
        sm[h]=0;
        if (o%kl[h]) mx[h]++, o=o%kl[h], sm[h]=kl[h]-o;
    }
    //cout << mx[h] << " " << sm[h] << "\n";
}

void solve()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        c[x].pb(i);
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    dfs(1);
    cout << mx[1] << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
/*

10
4 1 7 6 5 5 4 2 3 1
*/