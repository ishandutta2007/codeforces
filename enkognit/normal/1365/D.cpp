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

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ld E = 1e-8;
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 29, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

string ans;
ll n, m, k, h, T, TT, lst, nm=0;
string s[101];
bool tt[101][101];

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
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i]=' '+s[i];
    }
    ll kol=0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            tt[i][j]=0;
            if (s[i][j]=='B')
            {
                if (i>1)
                {
                    if (s[i-1][j]=='G') {cout << "No\n";return;}
                    if (s[i-1][j]!='B') s[i-1][j]='#';
                }
                if (i<n)
                {
                    if (s[i+1][j]=='G') {cout << "No\n";return;}
                    if (s[i+1][j]!='B')s[i+1][j]='#';
                }
                if (j>1)
                {
                    if (s[i][j-1]=='G') {cout << "No\n";return;}
                    if (s[i][j-1]!='B')s[i][j-1]='#';
                }
                if (j<m)
                {
                    if (s[i][j+1]=='G') {cout << "No\n";return;}
                    if (s[i][j+1]!='B')s[i][j+1]='#';
                }
            }
            if (s[i][j]=='G') kol++;
        }
    if (kol==0) {cout << "Yes\n";return;}
    if (s[n][m]=='#') {cout << "No\n";return;}
    queue<pll> q;
    q.push(mp(n,m));
    vector<pll> v;
    v.pb(mp(-1,0));
    v.pb(mp(1,0));
    v.pb(mp(0,-1));
    v.pb(mp(0,1));
    ll k=0;
    tt[n][m]=1;
    while (!q.empty())
    {
        ll x=q.front().fi, y=q.front().se;
        q.pop();
        if (s[x][y]=='G') k++;
        for (int i = 0; i < v.size(); i++)
        {
            ll xx=x+v[i].fi, yy=y+v[i].se;
            if (xx<1 || yy<1 || xx>n || yy>m || tt[xx][yy] || s[xx][yy]=='#') continue;
            tt[xx][yy]=1;
            q.push(mp(xx,yy));
        }
    }
    //cout << k << " " << kol << "\n";
    if (k==kol) cout << "Yes\n"; else cout << "No\n";
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
2 16
1 1 2
2 1 2
1 2 1
2 2 1
1 1 2
2 1 2
1 2 1
2 2 1
1 1 2
2 1 2
1 2 1
2 2 1
1 1 2
2 1 2
1 2 1
2 2 1
*/