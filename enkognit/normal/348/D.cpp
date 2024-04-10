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

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ld E = 1e-8;
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 29, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, dp[3005][3005];
string s[3005];

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

struct dsu
{
    ll d[200001];

    void make_set(int h)
    {
        d[h]=h;
    }

    ll find_set(int h)
    {
        if (h==d[h]) return h; else return d[h]=find_set(d[h]);
    }

    void unite_sets(int x,int y)
    {
        x=find_set(x);
        y=find_set(y);
        if (x<y) swap(x,y);
        d[x]=y;
    }
};

ll get_path(pll x,pll y)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) dp[i][j]=0;
    dp[x.fi][x.se]=1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s[i][j]!='#') dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD,
                              dp[i][j+1]=(dp[i][j+1]+dp[i][j])%MOD; else dp[i][j]=0;
    //cout << dp[y.fi][y.se] << "\n";
    return dp[y.fi][y.se];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i]=' '+s[i];
    }
    //if (n==1 || m==1 || s[n][m-1]=='#' || s[n-1][m]=='#' || s[1][2]=='#' || s[2][1]=='#')
    ll p=get_path(mp(1,2), mp(n-1,m))*get_path(mp(2,1), mp(n,m-1))%MOD;
    p-=get_path(mp(1,2), mp(n,m-1))*get_path(mp(2,1), mp(n-1,m))%MOD;
    if (p<0) p+=MOD;
    cout << p << "\n";
    return 0;
}

/*

*/