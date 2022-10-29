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


ll n, m, k, d, T, Q, ch[200001][32];
string s;

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

void solve()
{
    cin >> n >> k;
    cin >> s;
    s=' '+s;
    ll ans=0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j <= 'z'-'a'; j++) ch[i][j]=0;
        for (int j = i; j <= n; j+=k)
            ch[i][s[j]-'a']++;
    }
    for (int i = 1; i <= k/2; i++)
    {
        ll p=1e9;
        for (int j = 0 ;j <= 'z'-'a'; j++)
            p=min(p, n/k*2 - ch[i][j] - ch[k-i+1][j]);
        ans+=p;
    }
    if (k%2)
    {
        ll p=1e9;
        for (int i = 0; i <= 'z'-'a'; i++)
            p=min(p,n/k-ch[k/2+1][i]);
        ans+=p;
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   // freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
/*8

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