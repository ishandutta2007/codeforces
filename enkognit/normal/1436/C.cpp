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

const ll MOD = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, a[100001], fact[100001], infact[100001], kol=1;

ll binpow(ll h, ll r, ll md = MOD)
{
    bool t = 0;
    if (h < 0) t = 1, h = -h;
    if (r % 2 == 0) t = 0;
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    if (t) l = -l;
    //cout << l << "\n";
    return l;
}

ll C(ll n,ll k)
{
    return fact[n]*infact[k]%MOD*infact[n-k]%MOD;
}

void solve()
{
    ll x, ps, n;
    cin >> n >> x >> ps;
    ps++;
    ll u=0, d=0, l=0, r=n;
    while (l<r)
    {
        int w=(l+r)/2;
        //cout << w << " " << ps << "\n";
        if (w==ps-1)
        {
            l=w+1;
            continue;
        }
        if (w<ps)
        {
            if (x-d==1)
            {
                cout << "0\n";
                return;
            }
            d++;
            l=w+1;
        }else
        {
            if (x+u==n)
            {
                cout << "0\n";
                return;
            }
            u++;
            r=w;
        }
    }
    ll ans=1;
    //cout << d << " " << u << "\n";
    ans=(ans*C(x-1,d))%MOD;
    ans=(ans*fact[d])%MOD;
    ans=(ans*C(n-x,u))%MOD;
    ans=(ans*fact[u])%MOD;
    ans=(ans*fact[n-1-d-u])%MOD;
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    fact[0]=1;
    infact[0]=1;
    for (ll i = 1; i <= 10000; i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        infact[i]=binpow(fact[i],MOD-2);
    }
    ll t=1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
/*

10
4 1 7 6 5 5 4 2 3 1
*/