#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
/*#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")*/
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
const ll INF=1e18;
const ld E=1e-8;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, d, h, p, T, fact[1000001];

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

ll C(ll n,ll k)
{
    return (fact[n]*binpow(fact[k],MOD-2)%MOD*binpow(fact[n-k],MOD-2))%MOD;
}

void solve()
{
    cin >> n >> k;
    fact[0]=1;
    for (ll i = 1; i <= n; i++) fact[i]=(fact[i-1]*i)%MOD;
    if (k>=n)
    {
        cout << "0\n";
        exit(0);
    }
    ll p=(binpow(n-k,n))%MOD, z=0;
    for (int i = 1; i <= n-k; i++)
    {
        ll o=(C(n-k,i)*binpow((n-k-i), n))%MOD;
        //cout << o << "\n";
        if (i%2) z=(z+o)%MOD; else z-=o;
        if (z<0) z+=MOD;
    }
    ll ans=p-z;
    if (ans<0) ans+=MOD;
    if (k!=0) ans*=2;
    ans=(C(n,n-k)*ans)%MOD;
    cout << ans%MOD << "\n";
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
7 10
1 2
2 1
3 2
3 7
7 6
6 3
6 5
2 5
1 4
5 4
*/