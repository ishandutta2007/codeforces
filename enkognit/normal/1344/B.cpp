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

const ll MOD = 998244353;
const ll INF=1e18;
const ld E=1e-8;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T;
string s[1001];
bool tt[1001][1001];

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
    cin >> n >> m;
    bool T=0;
    ll ans=0;
    ll kl=0, Q=0, W=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i]=' '+s[i];
        ll q=0, t=0;
        for (int j = 1; j <= m; j++)
            if (s[i][j]=='.') t=0; else
        {
            kl++;
            q+=(t==0);
            t=1;
        }
        //cout << i << " " << q << "\n";
        if (q>1) T=1;
        if (q==0) Q++;
    }
    for (int i = 1 ;i <= m; i++)
    {
        ll q=0, t=0;
        for (int j = 1; j <= n; j++)
            if (s[j][i]=='.') t=0; else
        {
            q+=(t==0);
            t=1;
        }
        //cout << i << " " << q << "\n";
        if (q>1) T=1;
        if (q==0) W++;
    }
    if (T || (Q>0 && W==0) || (Q==0 && W>0)) {cout << "-1\n";return;}
    vector<pll> v;
    v.pb(mp(-1,0));
    v.pb(mp(1,0));
    v.pb(mp(0,-1));
    v.pb(mp(0,1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s[i][j]=='#' && !tt[i][j])
    {
        ans++;
        queue<pll> q;
        tt[i][j]=1;
        q.push(mp(i,j));
        while (!q.empty())
        {
            ll x=q.front().fi, y=q.front().se;

            q.pop();
            for (int i = 0; i < v.size(); i++)
            {
                ll xx=x+v[i].fi, yy=y+v[i].se;
                if (xx<1 || yy<1 || xx>n || yy>m || tt[xx][yy] || s[xx][yy]=='.') continue;
                tt[xx][yy]=1;
                q.push(mp(xx,yy));
            }
        }
    }
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
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}