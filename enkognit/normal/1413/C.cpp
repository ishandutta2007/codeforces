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

ll n, m, h, w, a[1001], b[100001], kl[1000001];

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
    for (int i = 1; i <= 6; i++)
        cin >> a[i];
    sort(a+1,a+6+1);
    cin >> n;
    vector<pll> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        for (int j = 1; j <= 6; j++)
            v.pb(mp(b[i]-a[j], i));
    }
    sort(all(v));
    ll l=0, r=2e9;
    while (l<r)
    {
        ll w=(l+r)/2;
        for (int i = 1; i <= n; i++) kl[i]=0;
        ll lr=0, o=0;
        bool tt=0;
        for (int i = 0; i < v.size(); i++)
        {
            kl[v[i].se]++;
            if (kl[v[i].se]==1) o++;
            while (v[lr].fi+w<v[i].fi)
            {
                kl[v[lr].se]--;
                if (kl[v[lr].se]==0) o--;
                lr++;
            }
            if (o==n)
            {
                tt=1;
                break;
            }
        }
        if (tt) r=w; else l=w+1;
    }
    cout << l << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
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

10
4 1 7 6 5 5 4 2 3 1
*/