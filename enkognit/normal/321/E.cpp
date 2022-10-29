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
#define ld double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int n, m, T, k, a[4001][4001], pr[4001][4001], sum[4001][4001], dp[4001][801];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l%=md;
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

void rec(int l,int r,int lr,int rr)
{
    if (l>r) return;
    int w=(l+r)/2, wr=lr;
    dp[w][T]=1e9;
    for (int i = lr; i <= min(rr, w-1); i++)
        if (dp[w][T]>dp[i][T-1]+sum[i+1][w])
        {
            dp[w][T]=min(dp[w][T], dp[i][T-1]+sum[i+1][w]);
            wr=i;
        }
    rec(l,w-1,lr,wr);
    rec(w+1,r,wr,rr);
}

void solve()
{
    cin >> n >> m;
    /*if (n==4000)
    {
        cout << "Time: " <<fixed<< ((ld)clock()/(ld)CLOCKS_PER_SEC) << "\n";
        exit(0);
    }*/
    string s;
    getline(cin, s);
    for (int i = 1; i <= n; i++)
    {
        getline(cin, s);
        for (int j = 0, u = 1; j < s.size(); j+=2, u++)
            a[i][u]=s[j]-'0';
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
        {
            pr[i][j]=pr[i][j-1]+a[i][j];
        }
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
        {
            sum[i][j]=sum[i][j-1]+(pr[j][j]-pr[j][i-1]);
        }
    for (int i = 1; i <= n; i++) dp[i][1]=sum[1][i];
    cout.precision(10);
    for (T=2;T<=m;T++)
    {
        rec(1,n,1,n);
    }
    /*for (int i = 1; i <= m; i++)
    {
        cout << i << " : ";
        for (int j = 1; j <= n; j++) cout << dp[j][i] << " ";
        cout << "\n";
    }*/
    cout << dp[n][m] << "\n";
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
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
4
3 2
1 2 2
4 3
1 2 3 4
2 2
1 2
11 4
66 152 7 89 42 28 222 69 10 54 99
*/