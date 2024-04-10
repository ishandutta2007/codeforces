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

const ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-8;
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 29, p3 = 7, p4=rnd()%100+1, md1 = MOD, md2 = 998244353, md3=998244357, md4=rnd()%1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, pr[300001], sf[300001];
vector<ll> v;
ll a[300001];

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
    string s;
    cin >> s;
    ll n=s.size();
    s=' '+s;
    pr[0]=0;
    sf[n+1]=0;
    for (int i = 1; i <= n; i++)
        pr[i]=pr[i-1]+(s[i]=='1');
    for (int i = n; i > 0; i--)
        sf[i]=sf[i+1]+(s[i]=='1');
    ll ans=1e18;
    for (int i = 1; i <= n; i++)
    {
        ans=min(ans, pr[i]+((n-i)-sf[i+1]));
        ans=min(ans, sf[i+1]+(i-pr[i]));
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
     ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
4
1 4 3 6
3
1 2 3
4
6 3 4 1
*/