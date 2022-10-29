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
#define ld double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ll INF=1e18;
const ld E=1e-8;
const ld pi=acos(-1);
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, n1, n2, n3, a[10001], ans[10001];
int dp[5001][5001];
//int d[5001][5001];
vector<ll> c[5001];
vector<ll> v[5001][2];

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

void dfs(int h)
{
    if (a[h]==1) v[T][0].pb(h); else v[T][1].pb(h);
    for (int i = 0; i < c[h].size(); i++)
        if (a[c[h][i]]==0) a[c[h][i]]=-a[h], dfs(c[h][i]); else
        if (a[c[h][i]]==a[h]) {cout << "NO\n";exit(0);}
}

int main()
{
    //freopen("input3.txt","r",stdin);
    //freopen("output3.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n >> m;
    cin >> n1 >> n2 >> n3;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    for (int i = 1; i <= n; i++)
        if (a[i]==0)
    {
        T++;
        a[i]=1;
        dfs(i);
    }

    for (int i = 1; i <= T; i++)
    {
        for (int j = n; j > -1; j--)
            if (dp[i-1][j]>0 || j==0 && i==1)
            {
                if (dp[i][j+v[i][0].size()]==0)
                {
                    dp[i][j+v[i][0].size()]=1;
                }
                if (dp[i][j+v[i][1].size()]==0)
                {
                    dp[i][j+v[i][1].size()]=2;
                }
            }
        //for (int j = 1; j <= n; j++) cout << d[i]
    }
    //cout << d[n2] << "\n";
    if (dp[T][n2]==0) {cout << "NO\n";exit(0);}
    ll p=n2;
    for (int j = T; j > 0; j--)
    {
        //cout << j << " " << p << " " << dp[j][p] << "\n";
        //if (dp[j][p]==0) {while(1);}
        for (int i = 0; i < v[j][dp[j][p]-1].size(); i++)
        {
            ans[v[j][dp[j][p]-1][i]]=2;
        }
        p=p-v[j][dp[j][p]-1].size();
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
    {
        if (ans[i]==0)
        {
            if (n1>0) {n1--;cout << "1";} else
                {n3--;cout << "3";}
        }else cout << "2";
    }

    return 0;
}