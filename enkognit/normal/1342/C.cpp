#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
/*#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")*/
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
const ll INF=1e18;
const ld E=1e-8;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, d, h, p, T;
vector<ll> c[100001];

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
    ll a, b, q;
    cin >> a >> b >> q;
    if (a>b) swap(a,b);
    ll p=a*b/__gcd(a,b);
    for (int i = 0; i < q; i++)
    {
        ll l, r, kl2=0, kl1=0;
        cin >> l >> r;
        l--;
        while (l%b!=b-1 && l>0)
        {
            kl1+=(l%a!=l%b%a);
            l--;
        }
        while (r%b!=b-1 && r>0)
        {
            kl2+=(r%a!=r%b%a);
            r--;
        }
        //cout << l << "-" << r << " " << kl2 << " " << kl1 << "\n";
        if (r>0)
        {
            r/=b;
            kl2+=(r-(r/(a/__gcd(a,b))))*b;
        }
        if (l>0)
        {
            l/=b;
            kl1+=(l-(l/(a/__gcd(a,b))))*b;
        }
        cout << kl2-kl1 << "\ ";
    }
    cout << "\n";
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
7 10
1 2
2 1
3 2
3 7
7 6
6 3
6 5
2 5
1 4
5 4
*/