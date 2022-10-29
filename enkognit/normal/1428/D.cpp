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

ll n, m, k, T, a[1000001], b[100001];

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

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<pll> v1, vv;
    vector<ll> v2;
    ll p=0;
    for (int i = n; i > 0; i--)
    {
        if (a[i]==1)
        {
            p++;
            v1.pb(mp(p, i));
            vv.pb(mp(p, i));
        }else
        if (a[i]==2)
        {
            if (v1.size()==0)
            {
                cout << "-1\n";
                return;
            }else
            {
                vv.pb(mp(v1.back().fi, i));
                v1.pop_back();
                v2.pb(i);
            }
        }else
        if (a[i]==3)
        {
            if (v1.size()==0 && v2.size()==0)
            {
                cout << "-1\n";
                return;
            }
            if (v2.size())
            {
                p++;
                vv.pb(mp(p, v2.back()));
                v2.pop_back();
                vv.pb(mp(p, i));
                v2.pb(i);
            }else
            {
                p++;
                vv.pb(mp(p, v1.back().se));
                v1.pop_back();
                vv.pb(mp(p, i));
                v2.pb(i);
            }
        }
    }
    for (int i = 0; i < vv.size(); i++)
    {
        if (n-vv[i].fi+1<1)
        {
            cout << "1\n";
            return;
        }
    }
    cout << vv.size() << "\n";
    for (int i = 0; i < vv.size(); i++)
    {
        cout << (n-vv[i].fi+1) << " " << vv[i].se << "\n";
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