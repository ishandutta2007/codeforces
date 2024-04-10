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

const ll MOD = 1e9+7;
const ll INF=1e18;
const ld E=1e-8;
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 29, md1 = MOD, md2 = 998244353;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T;
ll t;
vector<ll> v;

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

ld func(ld h)
{
    return abs(h-t);
}

void solve()
{
    ld h, c;
    cin >> h >> c >> t;
    ll ans=1;
    ld rz=func(h);
    ld o=c/2.+h/2.;
    if (func(o)<rz) ans=2, rz=func(o);
    if (t<=o)
    {
        cout << ans << "\n";
        return;
    }
    //cout << rz << " " << o << " " << t << " " << func(o) << "\n";
    /*ll l=3, r=1e9;
    while (l+3<r)
    {
        ll w1=l+(r-l+1)/3, w2=r-(r-l+1)/3;
        //cout << l << " " << w1 << " " << w2 << " " << r << "\n";
        if (func(1./2.*(h+c) + (h-c)*(1./2./(ld)w1)) < func(1./2.*(h+c) + (h-c)*(1./2./(ld)w2)))
            r=w2; else l=w1;
    }
    for (ll i = max(3ll, l-(ll)1e2); i <= r+1e2; i++)
    {
        if (func(1./2.*(h+c) + (h-c)*(1./2./(ld)i)) < rz) rz=func(1./2.*(h+c) + (h-c)*(1./2./(ld)i)), ans=i;
    }*/
    ld u=(h-c)/(2*(t-1./2.*(h+c)));
    u=max(u, (ld)3.);

    ll q1=floor(u), q2=q1+1;
    if (q1%2==0) q1--;
    if (q2%2==0) q2++;
    if (q1>2 && (func(1./2.*(h+c) + (h-c)*(1./2./(ld)q1)) < rz || abs(func(1./2.*(h+c) + (h-c)*(1./2./(ld)q1)) - rz)<E && q1<ans)) rz=func(1./2.*(h+c) + (h-c)*(1./2./(ld)q1)), ans=q1;
    if (q2>2 && (func(1./2.*(h+c) + (h-c)*(1./2./(ld)q2)) < rz || abs(func(1./2.*(h+c) + (h-c)*(1./2./(ld)q2)) - rz)<E && q2<ans)) rz=func(1./2.*(h+c) + (h-c)*(1./2./(ld)q2)), ans=q2;
    //cout << rz << "\n";
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
7 6
2 1 1
3 1 2
1 4 0
4 5 1
5 6 3
5 7 4
1 3
4 1
2 4
2 5
3 5
3 7
*/