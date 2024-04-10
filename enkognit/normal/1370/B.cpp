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

const ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-12;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, b[100001], a[100001];

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
    cin >> n;
    for (int i = 1; i <= 1000; i++) b[i]=0;
    vector<ll> v1, v0;
    for (int i = 1; i <= 2*n; i++)
    {
        cin >> a[i];
        if (a[i]%2) v1.pb(i); else v0.pb(i);
    }
    if (v1.size()%2)
    {
        //cout << v1.back() << " " << v0.back() << "\n";
        v1.pop_back();
        v0.pop_back();
    }else
    {
        if (v1.size()>1)
        {
            //cout << v1.back() << " ";
            v1.pop_back();
            //cout << v1.back() << "\n";
            v1.pop_back();
        }else
        {
            //cout << v0.back() << " ";
            v0.pop_back();
            //cout << v0.back() << "\n";
            v0.pop_back();
        }
    }
    for (int i = 0; i < v1.size(); i+=2)
        cout << v1[i] << " " << v1[i+1] << "\n";
    for (int i = 0; i < v0.size(); i+=2)
        cout << v0[i] << " " << v0[i+1] << "\n";
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
8 2
2 2 2 2 2 2 2 2
1 2

*/