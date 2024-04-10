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
#define do_anal exit(0)

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll md = 11234549;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, ans, a[200001], pr[200001];

ll binpow(ll h, ll r, ll md)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    return l;
}

ll inverse(ll h)
{
    return binpow(h, md-2, md);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pr[i]=pr[i-1]+a[i];
    }
    ll ans=0;
    set<pair<ll,int> > s;
    for (int i = 1; i <= n; i++)
    {
        //cout << i << "\n";
        for (auto j : s)
        {
            j.fi=-j.fi;
            //cout << " " << j.fi << " " << j.se << "\n";
            if (j.fi<pr[i-1]-a[i])
            {
                break;
            }
            if ((a[j.se]^a[i])==(pr[i-1]-pr[j.se])) ans++;
            //cout << " " << ans << "\n";
        }
        if (i>1)
        {
            s.insert(mp(-(pr[i-1]+a[i-1]), i-1));
        }
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
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
2 2 1
ab
ba
ba
ab

2 2 1
ab
cd
dc
ba

3 3 1
abc
acc
adc
cda
acc
cba

*/