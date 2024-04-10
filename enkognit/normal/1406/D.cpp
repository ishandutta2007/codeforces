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

ll MOD = 1e9+7;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, a[1000001], b[1000001];
vector<ll> c[100001];
bool tt[100001];

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
    if (x==0 || y==0) return x+y;
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

vector<ll> v;
ll mn=1e18, q;

struct segment_tree
{
    ll d[1000001];
    ll b[1000001];

    void update(int h,int l,int r,int x,int k)
    {
        if (l==r)
        {
            b[h]+=k;
            d[h]=max(b[h], 0ll);
            return;
        }
        int w=(l+r)/2;
        if (x<=w) update(h*2,l,w,x,k); else update(h*2+1,w+1,r,x,k);
        d[h]=d[h*2]+d[h*2+1];
    }
};

segment_tree g;

void solve()
{
    cin >> n;
    ll o=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i>1)
        {
            //cout << a[i]-a[i-1] << "\n";
            g.update(1,2,n,i, a[i]-a[i-1]);
        }
    }
    //cout << o << "\n";
    if (a[1]>g.d[1])
    {
        cout << a[1]-abs(a[1]-g.d[1])/2 << "\n";
    } else
    {
        cout << g.d[1]-abs(a[1]-g.d[1])/2 << "\n";
    }
    cin >> q;
    while (q--)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        if (l==1) a[1]+=x;
        if (l>1) g.update(1,2,n,l,x);
        if (r<n) g.update(1,2,n,r+1,-x);
        if (a[1]>g.d[1])
    {
        cout << a[1]-abs(a[1]-g.d[1])/2 << "\n";
    } else
    {
        cout << g.d[1]-abs(a[1]-g.d[1])/2 << "\n";
    }
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
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
1
4
1 2 9 13
5 6 10 14
3 7 11 15
4 8 12 16
*/