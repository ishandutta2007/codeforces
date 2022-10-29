#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
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


//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, d, h, TT, T, L, n1, n2, n3, R, mx=0, ans, dp[3002][3003], dd[3002][3002];
vector<ll> v;

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
    cin >> s;
    cin >> d;
    ll n=s.size();
    ll m=d.size();
    s=' '+s;
    d=' '+d;
    dp[n+1][0]=1;
    for (int i = n+1; i > 1; i--)
    {
        if (m-i+1>=0 && m-i+1!=m)
        {
            dd[i][m-i+1]=(dd[i][m-i+1]+dp[i][m-i+1])%MOD;
            //cout << i << " " << m-i+1 << " " << dp[i][m-i+1] << "\n";
        }
        for (int j = max(m-i+2,0ll); j < m; j++)
        {
            ll k=0;
            if (j==0) k=1;
            dp[i-1][j]=(dp[i-1][j]+dp[i][j]+k)%MOD;
            if (d[j+1]==s[i-1]) dp[i-1][j+1]=(dp[i-1][j+1]+dp[i][j])%MOD;
        }
        //cout << i << " " << dp[i][m] << "\n";
        ans=(ans+dp[i][m]*binpow(2,i-1))%MOD;
    }
    for (int i = m+1; i > 1; i--)
    {
        for (int j = 0; j <= min(m-i+1,m-1); j++)
        {
            ll k=0;
            if (j==0) k=1;
            if (s[i-1]==d[j+1]) dd[i-1][j+1]=(dd[i-1][j+1]+dd[i][j])%MOD;
            if (s[i-1]==d[i+j-1]) dd[i-1][j]=(dd[i-1][j]+dd[i][j])%MOD;
        }
        //ans=(ans+dd[i][m]*binpow(2,i-1))%MOD;
    }
    for (int i = 0; i <= m; i++)
    {
        //cout << i << " : " << dd[1][i] << "\n";
        ans=(ans+dd[1][i])%MOD;
    }
    cout << ans << "\n";
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
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
2
3 2
10
01
01
DL
RU
UU
2 4
1111
0101
RDRD
UUUU
*/