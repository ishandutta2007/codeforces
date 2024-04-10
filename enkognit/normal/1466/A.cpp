#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
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

const ll MOD = 999999001;
const ll md = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 29, p2 = 17, p3 = 13, md1 = MOD, md2 = md, md3 = 998244353;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, K, a[200001];
vector<ll> c[200001];

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

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<ll> v;
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
        {
            v.pb(a[j]-a[i]);
        }
    sort(all(v));
    ll ans=0;
    for (int i = 0; i < v.size(); i++)
        if (i==0 || v[i]!=v[i-1]) ans++;
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


/*
MON
AMONGUS
3
*/