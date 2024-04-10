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

const ll MOD = 998244353;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, d, T, Q, dp[300001][3], ans;
string s;
vector<ll> c[300001];

ll binpow(ll h, ll r, ll md = MOD)
{
    bool t=0;
    if (h<0) t=1, h=-h;
    if (r%2==0) t=0;
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    if (t) l=-l;
    //cout << l << "\n";
    return l;
}

ll gcd(int x, int y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

ll gt(ll x,ll y)
{
    x%=MOD;
    y%=MOD;
    return (x*y)%MOD;
}

void dfs(int h,int p=-1)
{
    dp[h][0]=1;
    dp[h][1]=1;
    dp[h][2]=1;
    vector<vector<ll> > v;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            vector<ll> vv;
            dfs(c[h][i], h);
            vv.pb(dp[c[h][i]][0]);
            vv.pb(dp[c[h][i]][1]);
            vv.pb(dp[c[h][i]][2]);
            v.pb(vv);
        }
    ll p0=1, p1=1;
    for (int i = 0; i < v.size(); i++)
    {
        dp[h][0]=gt(dp[h][0], ((v[i][0]+v[i][1])+(v[i][0]+v[i][1]-v[i][2])+MOD)%MOD);
        dp[h][1]=gt(dp[h][1], ((v[i][0])+(v[i][0]+v[i][1]-v[i][2])+MOD)%MOD);
        dp[h][2]=gt(dp[h][2], (v[i][0]+v[i][1]-v[i][2]+MOD)%MOD);
    }
    //cout << h << " : " << dp[h][0] << " " << dp[h][1] << " " << dp[h][2] << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   // freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    dfs(1);
    cout << (dp[1][0]+dp[1][1]-dp[1][2]-1+MOD)%MOD;
    return 0;
}
/*

10
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb

*/