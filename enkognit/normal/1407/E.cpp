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

ll MOD = 1e9+7;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, T;
vector<pll> g[500001];

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

ll cl[500001], rst[500001];
bool tt[500001];

void solve()
{
    cin >> n >> m;
    if (n==1)
    {
        cout << "0\n0\n";
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        ll x, y, h;
        cin >> x >> y >> h;
        g[y].pb(mp(x,h+1));
    }
    queue<int> q;
    //for (int i = 0; i < g[n].size(); i++) cout << g[n][i].fi << " " << g[n][i].se << "\n";
    q.push(n);
    rst[1]=-1;
    while (!q.empty())
    {
        ll x=q.front();
        q.pop();
        sort(all(g[x]));
        bool t1=0, t2=0;
        for (int i = 0; i < g[x].size(); i++)
        {
            if (g[x][i].se==1) t1|=1; else t2|=1;
            if (i+1<g[x].size() && g[x][i+1].fi==g[x][i].fi)
            {
                continue;
            }else
            {
                //cout << g[x][i].fi << " " << t1 << " " << t2 << "\n";
                if (cl[g[x][i].fi])
                {
                    if (!tt[g[x][i].fi])
                    if (cl[g[x][i].fi]==1 && t1 || cl[g[x][i].fi]==2 && t2)
                    {
                        rst[g[x][i].fi]=rst[x]+1;
                        tt[g[x][i].fi]=1;
                        q.push(g[x][i].fi);
                    }
                }else
                if (t1 && t2)
                {
                    cl[g[x][i].fi]=1;
                    rst[g[x][i].fi]=rst[x]+1;
                    tt[g[x][i].fi]=1;
                    q.push(g[x][i].fi);
                }else
                {
                    if (t1)
                    {
                        cl[g[x][i].fi]=2;
                    }else
                    {
                        cl[g[x][i].fi]=1;
                    }
                }
                t1=0;t2=0;
            }
        }
    }
    cout << rst[1] << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (cl[i]==0) cl[i]=1;
        cout << cl[i]-1;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
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