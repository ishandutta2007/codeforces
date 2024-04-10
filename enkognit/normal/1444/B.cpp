#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, q, T, Z, fact[300001], infact[300001], a[300001];

ll binpow(ll h, ll r, ll md=MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    //cout << l << "\n";
    return l;
}

ll C(ll n,ll k)
{
    return fact[n]*infact[k]%MOD*infact[n-k]%MOD;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n*2; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n*2+1);
    ll x=0;
    for (int i = 1; i <= n*2; i++)
    {
        if (i<=n) x-=a[i]; else x+=a[i];
    }
    x%=MOD;
    cout << (x*C(n*2,n))%MOD << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("document.in","r",stdin);
    //freopen("document.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    fact[0]=1;
    infact[0]=1;
    for (ll i = 1; i <= 300000; i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        infact[i]=binpow(fact[i],MOD-2);
    }
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}