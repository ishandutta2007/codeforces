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

const ll MOD = 998244353;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, q, ans, mx, o, a[200001];
vector<ll> c[200001];
bool tt[200001];

ll binpow(ll h, ll r, ll md=MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    //cout << l << "\n";
    return l;
}

void dfs(int h,int k,int p,int nw)
{
    if (k>mx)
    {
        mx=k;
        o=h;
    }
    //if (a[h]==0) a[h]=nw;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            if (a[c[h][i]]) dfs(c[h][i], k+(nw!=a[c[h][i]]), h, a[c[h][i]]); else dfs(c[h][i], k, h, nw);
        }
}


void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    ans=1;
    ll p=-1;
    for (int i = 1; i <= n; i++)
        if (a[i]) {p=i;break;}
    if (p==-1) cout << "1\n"; else
    {
        mx=1;o=p;
        dfs(p,1,-1,a[p]);
        dfs(o,1,-1,a[o]);
        cout << mx/2+1 << "\n";
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("document.in","r",stdin);
    //freopen("document.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*fact[0]=1;
    infact[0]=1;
    for (ll i = 1; i <= 300000; i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        infact[i]=binpow(fact[i],MOD-2);
    }*/
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


/*
8
1 2 1 2 2 2 1 2
1 3
2 3
3 4
4 5
5 6
5 7
5 8

*/