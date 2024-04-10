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

ll n, m, a[1000001];

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

void solve()
{
    string s;
    cin >> s;
    ll ans=0;
    ll n=s.size();
    ll kl1=0, kl2=0;
    for (int i = 0; i < n; i++)
    {
        if (s[i]=='[') kl1++;
        if (s[i]=='(') kl2++;
        if (s[i]==']')
        {
            if (kl1) kl1--, ans++;
        }
        if (s[i]==')')
        {
            if (kl2) kl2--, ans++;
        }
    }
    cout << ans << "\n";
    /*ll kl=0, mx=0;
    vector<ll> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        kl+=a[i];
        v.pb(a[i]);
    }
    ll ans=(n-kl%n)%n;
    */
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
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