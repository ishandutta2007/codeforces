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
const ll INF = 1e18;
const ld E = 1e-8;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T;
ll a[1001][1001];
bool tt[1001][1001];
string s[1001];

ll binpow(ll h, ll r)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h;// l %= md;
        h *= h;
        //h %= md;
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
    ll t;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i]=' '+s[i];
    }
    queue<pair<pii,int> > q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (i>1 && s[i-1][j]==s[i][j]) q.push(mp(mp(i,j),0)), tt[i][j]=1, a[i][j]=0;else
            if (i<n && s[i+1][j]==s[i][j]) q.push(mp(mp(i,j),0)), tt[i][j]=1, a[i][j]=0;else
            if (j>1 && s[i][j-1]==s[i][j]) q.push(mp(mp(i,j),0)), tt[i][j]=1, a[i][j]=0;else
            if (j<m && s[i][j+1]==s[i][j]) q.push(mp(mp(i,j),0)), tt[i][j]=1, a[i][j]=0;
        }
    vector<pii> v;
    v.pb(mp(-1,0));
    v.pb(mp(1,0));
    v.pb(mp(0,-1));
    v.pb(mp(0,1));
    if (q.size()==0)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) a[i][j]=1e18+1;
    }
    while (!q.empty())
    {
        ll x=q.front().fi.fi, y=q.front().fi.se, k=q.front().se;
        q.pop();
        for (int i = 0; i < v.size(); i++)
        {
            ll xx=x+v[i].fi, yy=y+v[i].se;
            if (xx<1 || yy<1 || xx>n || yy>m) continue;
            if (tt[xx][yy]) continue;
            a[xx][yy]=k+1;
            tt[xx][yy]=1;
            q.push(mp(mp(xx,yy),k+1));
        }
    }
    while (t--)
    {
        ll x, y, p;
        cin >> x >> y >> p;
        if (p<=a[x][y]) cout << s[x][y] << "\n"; else
        {
            ll o=s[x][y]-48;
            cout << (o+(p-a[x][y])%2)%2 << "\n";
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