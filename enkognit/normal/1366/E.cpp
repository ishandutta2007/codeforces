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
const ll INF = 1e18;
const ld E = 1e-9;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, kol=0, sz=0, a[200005], b[200005];

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

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    ll l=n+1, mn=1e18, ans=1;
    vector<int> v;
    for (int j = m; j > 0; j--)
    {
        ll p=0;
        //if (j==m) p=n;
        while (l>1 && min(mn,a[l-1])>=b[j])
        {
            l--, mn=min(mn,a[l]);
            if (mn==b[j]) p=max(p,l);
        }
        p=max(p,l);
        if (mn!=b[j]) {cout << "0\n";exit(0);}
        //cout << l << " " << p << " " << mn << " " << b[j] << "\n";
        if (j>1)ans=(ans*(p-l+1))%MOD;
        //v.pb(n-l+1);
    }
    if (l>1) ans=0;
    cout << ans << "\n";
    //for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    //cout << "\n";
    return 0;
}

/*
8 2
2 2 2 2 2 2 2 2
1 2

*/