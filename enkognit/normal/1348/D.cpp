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

ll n, m, k, d, h, p, T, a[10001];
bool tt[1001];

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
    ll n;
    cin >> n;
    vector<ll> v;
    vector<ll> ans;
    ll j=0, k=0;
    while (1)
    {
        v.pb((1ll<<j));
        k+=v.back();
        if (k>=n) break;
        j++;
    }
    cout << v.size()-1 << "\n";
    n-=v.size();
    for (int i = 1; i < v.size(); i++)
    {
        ll k=min(n/(v.size()-i),v[i]-v[i-1]);
        ans.pb(k);
        n-=k*(v.size()-i);
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << "\n";
    return;
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
        //cout << t << "\n";
        solve();
    }
    return 0;
}
/*
3
7 10
1 7
7 3

10

816 94 166 114 475 699 974 462 61 337

816 94 166 114 475 699 462 61 1311

94 166 114 475 699 1278 61 1311

94 166 175 475 699 1278 1311

*/