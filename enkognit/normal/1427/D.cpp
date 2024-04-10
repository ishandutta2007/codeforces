#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, a[1000001], b[1000001];
vector<ll> f, s;
vector<vector<ll> > v;
vector<ll> vv;

ll binpow(ll h, ll r, ll md = MOD)
{
    bool t = 0;
    if (h < 0) t = 1, h = -h;
    if (r % 2 == 0) t = 0;
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    if (t) l = -l;
    //cout << l << "\n";
    return l;
}

ll gcd(int x, int y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

void make(vector<ll> &s,vector<ll> &vv)
{
    vector<ll> p;
    p.pb(0);
    ll l=s.size();
    for (int i = vv.size()-1; i > -1; i--)
    {
        for (int j = l-vv[i]; j <= l-1; j++) p.pb(s[j]);
        l-=vv[i];
    }
    s=p;
}

void solve()
{
    cin >> n;
    f.pb(0);
    s.pb(0);
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        f.pb(x);
        s.pb(i);
    }
    for (int i = 1; i <= n/2; i++)
    {
        vector<ll> u;
        for (int j = 1; j <= n; j++)
            if (s[j]==f[i] || s[j]==f[n-i+1]) u.pb(j);
        v.pb(vv);
        for (int j = 1; j < i; j++) v.back().pb(1);
        v.back().pb(u[0]-i+1);
        if (u[1]-u[0]-1>0) v.back().pb(u[1]-u[0]-1);
        v.back().pb(n-u[1]+1-i+1);
        for (int j = 1; j < i; j++) v.back().pb(1);
        //cout << u[0] << " " << u[1] << "\n:";
        //for (int i = 0; i < v.back().size(); i++) cout << v.back()[i] << " ";
        //cout << "\n";
        make(s,v.back());
        //cout << " : ";
        //for (int i = 1; i <= n; i++ )cout << s[i] << " ";
        //cout << "\n";
    }
    //cout << v.size() << "\n";
    //for (int i = 1; i <= n; i++) cout << s[i] << " ";
    //cout << "\n";
    for (int i = n/2; i > 0; i--)
    {
        if (f[i]!=s[i])
        {
            v.pb(vv);
            for (int j = 1; j <= i; j++)
                v.back().pb(1);
            if ((n-i+1)-i-1>0) v.back().pb((n-i+1)-i-1);
            for (int j = 1; j <= i; j++)
                v.back().pb(1);
            make(s, v.back());
        }
        //cout << i << "\n ";
        //for (int i = 1; i <= n; i++) cout << s[i] << " ";
        //cout << "\n";
    }
    //for (int i = 1; i <= n; i++) cout << s[i] << " ";
    //cout << "\n";
    cout << v.size() << "\n";
    for (int i = v.size()-1;i > -1; i--)
    {
        cout << v[i].size() << " ";
        for (int j = v[i].size()-1; j > -1; j--)
            cout << v[i][j] << " ";
        cout << "\n";
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
5 3
5 2 2 3 1
1 4 4
3 5 4
3 4 1
*/