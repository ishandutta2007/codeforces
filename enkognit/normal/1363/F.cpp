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

ll n, m, k, h, T, prs[2005][26], prd[2005][26], dp[2001][2001];

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

void solve()
{
    string s, d;
    cin >> n;
    cin >> s;
    cin >> d;
    reverse(all(s));
    reverse(all(d));
    for (int i = 0; i < s.size(); i++)
        for (int j = 0; j < 26; j++)
            prs[i+1][j]=prs[i][j]+((s[i]-'a')==j);
    for (int i = 0; i < d.size(); i++)
        for (int j = 0; j < 26; j++)
            prd[i+1][j]=prd[i][j]+((d[i]-'a')==j);
    for (int i = 0; i < 26; i++)
        if (prs[n][i]!=prd[n][i])
        {
            cout << "-1\n";
            return;
        }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) dp[i][j]=1e18;

    dp[0][0]=0;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i; j++)
        {
            if (i<n && j<n && s[i]==d[j])
            {
                dp[i+1][j+1]=min(dp[i+1][j+1], dp[i][j]);
            }
            if (i<n)
            {
                dp[i+1][j]=min(dp[i+1][j], dp[i][j]+1);
            }
            if (j<n && prs[i][d[j]-'a'] > prd[j][d[j]-'a'])
            {
                dp[i][j+1]=min(dp[i][j+1], dp[i][j]);
            }
        }
    cout << dp[n][n] << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
3
5
abcab
aabab
3
aaa
aab
2
de
cd
*/