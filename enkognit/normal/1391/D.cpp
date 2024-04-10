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

ll MOD = 1e9+7;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, T, P, S, dp[1000001][2][2];

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

void solve()
{
    cin >> n >> m;
    vector<vector<bool> > aa(n), a(min(n,m));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        aa[i].resize(m, 0);
        for (int j = 0; j < m; j++) aa[i][j]=s[j]-'0';
    }
    if (n>3 && m>3)
    {
        cout << "-1\n";
        return;
    }
    if (n==1 || m==1)
    {
        cout << "0\n";
        return;
    }
    if (n>m)
    {
        swap(n,m);
        for (int i = 0; i < n; i++)
        {
            a[i].resize(m);
            for (int j = 0; j < m; j++) a[i][j]=aa[j][i];
        }
    }else
    {
        for (int i = 0; i < n; i++)
        {
            a[i].resize(m);
            for (int j = 0; j < m; j++) a[i][j]=aa[i][j];
        }
    }
    if (n==2)
    {
        ll o1=0, o2=0;
        for (int i = 0; i < m; i++)
        {
            o1+=(i%2!=(a[0][i]+a[1][i])%2);
            o2+=(i%2==(a[0][i]+a[1][i])%2);
        }
        cout << min(o1,o2) << "\n";
    }else
    {
        ll o1=(a[0][0]+a[1][0])%2;
        ll o2=(a[2][0]+a[1][0])%2;
        dp[0][o1][o2]=0;
        dp[0][(o1+1)%2][o2]=1;
        dp[0][o1][(o2+1)%2]=1;
        dp[0][(o1+1)%2][(o2+1)%2]=1;
        for (int i = 0; i < m-1; i++)
        {
            for (int u1 = 0; u1 < 2; u1++)
                for (int u2 = 0; u2 < 2; u2++) dp[i+1][u1][u2]=1e18;
            for (int u1 = 0; u1 < 2; u1++)
                for (int u2 = 0; u2 < 2; u2++)
                {
                    int o1=(a[0][i+1]+a[1][i+1])%2;
                    int o2=(a[2][i+1]+a[1][i+1])%2;
                    int o=(u1==o1 || u2==o2);
                    dp[i+1][(u1+1)%2][(u2+1)%2]=min(dp[i+1][(u1+1)%2][(u2+1)%2], dp[i][u1][u2]+o);
                }
        }
        ll ans=1e18;
        for (int u1 = 0; u1 < 2; u1++)
            for (int u2 = 0; u2 < 2; u2++) ans=min(dp[m-1][u1][u2], ans);
        cout << ans << "\n";
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
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}