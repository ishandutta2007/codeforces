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

ll n, m, k, h, T, ans, tt[300001], kl[300001], k1=0, k0=0;
vector<ll> v[300001];
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
    cin >> n >> k;
    for (int i = 1; i <= n; i++) tt[i]=-1;
    for (int i = 0; i < k; i++)
    {
        ll x;
        cin >> x;
        v[i].clear();
        vector<ll> w;
        for (int j = 0; j < x; j++)
        {
            ll y;
            cin >> y;
            w.pb(y);
            tt[y]=i;
        }
        sort(all(w));
        ll l=1;
        for (int j = 0; j < w.size(); j++)
        {
            while (l<w[j]) v[i].pb(l), l++;
            l++;
        }
        while (l<=n) v[i].pb(l), l++;
    }
    cout << "? " << n << " ";
        for (int i = 1; i <= n; i++) cout << i << " ";
        cout << "\n";
    ll mx=0;
    cin >> mx;
    fflush(stdout);
    ll l=1, r=n;
    while (l<r)
    {
        int w=(l+r)/2;
        cout << "? " << w-l+1 << " ";
        for (int i = l; i <= w; i++) cout << i << " ";
        cout << "\n";
        ll q;
        cin >> q;
        fflush(stdout);
        if (q==mx) r=w; else l=w+1;
    }
    string s;
    if (tt[l]==-1)
    {
        cout << "! ";
        for (int i = 0; i < k; i++) cout << mx << " ";
        cout << "\n";
        cin >> s;
    }else
    {
        ll o=0, j=tt[l];
        cout << "? " << v[j].size() << " " ;
        for (int i = 0; i < v[j].size(); i++) cout << v[j][i] << " ";
        cout << "\n";
        ll p;
        cin >> p;
        fflush(stdout);
        cout << "! ";
        for (int i = 0; i < k; i++) if (i==j) cout << p << " "; else cout << mx << " ";
        cout << "\n";
        cin >> s;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
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