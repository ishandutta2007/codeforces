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

ll n, m, k, q, T, Z, a[300001], b[1000001], z[1000001], tt[1000001];

//ll fact[300001], infact[300001];


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

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        z[a[i]]=i;
    }
    for (int i = 1; i <= n; i++) tt[i]=0;
    for (int i = 1; i <= k; i++)
    {
        cin >> b[i];
        b[i]=z[b[i]];
        tt[b[i]]=1;
    }
    tt[0]=1;
    tt[n+1]=1;
    ll ans=1;
    for (int i = 1; i <= k; i++)
    {
        ll o=2-(tt[b[i]-1])-(tt[b[i]+1]);
        //cout << b[i] << " " << o << "\n";
        ans=(ans*o)%MOD;
        tt[b[i]]=0;
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("document.in","r",stdin);
    //freopen("document.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*fact[0]=1;
    infact[0]=1;
    for (ll i = 1; i <= 300000; i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        infact[i]=binpow(fact[i],MOD-2);
    }*/
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}