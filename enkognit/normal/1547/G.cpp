#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
//#include "testlib.h"
//#pragma GCC optimize("popcnt")
#include <random>
#include <time.h>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

mt19937_64 rnd(time(0));

ll MOD=1e9+7;
const ld E=1e-10;

ll n, m, k, T, out[400001], zz[400001], ans[400001];
vector<ll> c[400001], gg[400001], v, vv;
bool tt[400001], tl[400001], ww[400001];

struct dsu
{
    ll d[400001];

    void make_sets(int h)
    {
        for (int i = 1; i <= h; i++)
            d[i]=i;
    }

    ll find_set(int h)
    {
        if (h==d[h]) return h; else return d[h]=find_set(d[h]);
    }

    void unite_sets(int x,int y)
    {
        x=find_set(x);
        y=find_set(y);
        d[x]=y;
    }
} g;

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%md;
        h=(h*h)%md;
        r/=2;
    }
    return l;
}

ll read()
{
    char c=getchar();
    while (!isdigit(c))
    {
        c=getchar();
    }
    ll res=0;
    while (isdigit(c))
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

ll gcd(ll x,ll y)
{
    while (x && y)
    {
        if (x<y) swap(x, y);
        x%=y;
    }
    return x+y;
}

void dfs(int h)
{
    tt[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]])
            dfs(c[h][i]);
    v.pb(h);
}

void dfs2(int h)
{
    tt[h]=1;
    tl[h]=1;
    //cout << h << "\n";
    g.unite_sets(h, T);
    for (int i = 0; i < gg[h].size(); i++)
        if (!tt[gg[h][i]])
        {
            dfs2(gg[h][i]);
        }else
        if (tl[gg[h][i]])
            zz[T]=1;
    vv.pb(h);
}

void solve()
{
    cin >> n >> m;

    g.make_sets(n);
    for (int i = 1; i <= n; i++)
        c[i].clear(), gg[i].clear(), tt[i]=0, ans[i]=0, zz[i]=0, ww[i]=0;

    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        gg[y].pb(x);
    }

    queue<ll> q;
    q.push(1);
    ww[1]=1;
    while(!q.empty())
    {
        ll h=q.front();
        q.pop();
        for (int i = 0; i < c[h].size(); i++)
            if (!ww[c[h][i]])
            {
                ww[c[h][i]]=1;
                q.push(c[h][i]);
            }
    }

    for (int i = 1; i <= n; i++)
        if (!tt[i])
        {
            dfs(i);
        }

    for (int i = 1; i <= n; i++) tt[i]=0;

    reverse(all(v));
    //cout << "-----\n";
    for (int i = 0; i < v.size(); i++)
        if (!tt[v[i]])
        {
            T=v[i];
            //cout << v[i] << "\n";
            dfs2(v[i]);
            //cout << " " << zz[v[i]] << "\n";
            while (vv.size()>0)
            {
                tl[vv.back()]=0;
                vv.pop_back();
            }
            //cout << "-\n";
        }

    //cout << "-----\n";

    for (int i = 1; i <= n; i++)
        tt[i]=0;

    for (int i = 1; i <= n; i++)
        if (zz[i] && ww[i]) q.push(i);

    while (!q.empty())
    {
        ll x=q.front();
        q.pop();
        for (int i = 0; i < c[x].size(); i++)
            if (!tt[c[x][i]])
            {
                q.push(c[x][i]);
                tt[c[x][i]]=1;
            }
    }

    for (int i = 1; i <= n; i++)
        if (tt[i]) ans[i]=-1;

    if (ans[1]!=-1)
    {
        q.push(1);
        ans[1]=1;
    }

    while(!q.empty())
    {
        ll h=q.front();
        q.pop();
        for (int i = 0; i < c[h].size(); i++)
            if (ans[c[h][i]]!=-1)
        {
            if (ans[c[h][i]]<2)
            {
                q.push(c[h][i]);
                ans[c[h][i]]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (!ww[i]) cout << "0 "; else cout << min(2ll,ans[i]) << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}