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

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ld E = 1e-8;
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int n, m, k, h, T, kol=0, sz=0, a[401], dp[401][401][401];

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

ll basis[21];

void insert_into_basis(int h)
{
    for (int i = 0; i < 20; i++)
        if (h&(1<<i))
        {
            if (basis[i]==0)
            {
                basis[i]=h;
                sz++;
                return;
            }
            h^=basis[i];
        }
}

bool check(int h)
{
    for (int i = 0; i < 20; i++)
        if (h&(1<<i))
        {
            if (basis[i]==0)
            {
                return 0;
            }
            h^=basis[i];
        }
    return 1;
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
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            for (int u = 0; u <= n; u++)
            {
                if (u==0) dp[i][j][u]=a[j]-a[i]; else
                    dp[i][j][u]=1e9+1;
            }
    for (int i = 1; i <= n; i++)
        for (int u = 1; u <= n; u++)
        {
            ll l=i;
            for (int j = i+1; j <= n; j++)
            {
                while (l+1<j && max(dp[i][l][u-1],a[j]-a[l])>=max(dp[i][l+1][u-1],a[j]-a[l+1])) l++;
                dp[i][j][u]=max(dp[i][l][u-1],a[j]-a[l]);
            }
        }
    ll ans=0;
    for (int i = 1; i <= m; i++)
    {
        ll x, y, u, p;
        cin >> x >> y >> u >> p;
        //cout << dp[x][y][p] << "\n";
        ans=max(ans,dp[x][y][p]*u);
    }
    cout << ans << "\n";
    return 0;
}

/*
5
hello
bye
hellohello
byebye
h

*/