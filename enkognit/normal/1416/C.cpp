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
#define ld double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-10;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll a[300005];
pll zz[35];

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

void rec(vector<int> v,ll o)
{
    if (v.size()==0) return;
    //system("pause");
    vector<int> w1, w0;
    for (int i = 0; i < v.size(); i++)
    {
        if ((a[v[i]]&(1<<o))) w1.pb(v[i]); else w0.pb(v[i]);
    }
    ll l=0, kol=0;
    for (int i = 0; i < w0.size(); i++)
    {
        while (l<w1.size() && w1[l]<w0[i]) l++;
        kol+=l;
    }
    if (o>0)
    {
        rec(w1, o-1);
        rec(w0, o-1);
    }
    zz[o].fi+=kol;
    zz[o].se+=(ll)((ll)w1.size()*(ll)w0.size())-kol;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<int> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];q.pb(i);
    }
    rec(q, 30);
    ll ans=0, p=0;
    for (int i = 0; i <= 30; i++)
    {
        if (zz[i].se<zz[i].fi) ans+=(1<<i);
        p+=min(zz[i].fi, zz[i].se);
    }
    cout << p << " " << ans << "\n";
    return 0;
}
/*
6
2 1 13
3 1 18
1 4 8
4 5 15
4 6 11

*/