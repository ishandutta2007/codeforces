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
#define ld double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, T, P, a[500001];
vector<ll> v;

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l%=md;
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
    cin >> n;
    ll k2=0, k4=0, k6=0, k8=0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        a[x]++;
        if (a[x]==2) k2++;
        if (a[x]==4) k4++;
        if (a[x]==6) k6++;
        if (a[x]==8) k8++;
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll x;
        char c;
        cin >> c >> x;
        if (c=='+')
        {
            a[x]++;
            if (a[x]==2) k2++;
            if (a[x]==4) k4++;
            if (a[x]==6) k6++;
            if (a[x]==8) k8++;
        }else
        {
            a[x]--;
            if (a[x]==1) k2--;
            if (a[x]==3) k4--;
            if (a[x]==5) k6--;
            if (a[x]==7) k8--;
        }
        bool tt=0;
        if (k8) tt=1;
        if (k6>1) tt=1;
        if (k6==1)
        {
            if (k2>1) tt=1;
        }
        if (k4>1) tt=1;
        if (k4==1)
        {
            if (k2>2) tt=1;
        }
        cout << (tt?"YES":"NO") << "\n";
    }
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
    while(t--)
    {
        solve();
    }
    return 0;
}