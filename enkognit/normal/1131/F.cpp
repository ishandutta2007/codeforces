#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define pll pair<ll,ll>
#define ld long double
#define sqr(a) ((a)*(a))

using namespace std;

ll n, m, i, k, ans, l, r, no, yes, x[1000001], y[1000001];
map<ll,bool> tt={};
vector <ll> c[200001];
string s, d;

struct dsu
{
    ll p[200001];
    pll q[200001];

    make_dsu(ll x)
    {
        p[x]=x;
        q[x]=mp(x,x);
    }

    find_dsu(ll x)
    {
        if (p[x]==x) return x; else return p[x]=find_dsu(p[x]);
    }

    union_dsu(ll x,ll y)
    {
        x=find_dsu(x);
        y=find_dsu(y);
        if (x!=y)
        {
            p[x]=y;
            q[y].fi=q[x].se;
        }
    }
};

dsu t;

void dfs(ll h)
{
    tt[h]=1;
    cout << h << " ";
    for (int i = 0; i < c[h].size(); i++) if (!tt[c[h][i]]) dfs(c[h][i]);
}

int main()
{
    //freopen("roulette.in","r",stdin);
    //freopen("roulette.out","w",stdout);
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) t.make_dsu(i);
    for (int i = 0; i < n-1; i++)
    {
        ll x, y;
        cin >> x >> y;
        x=t.find_dsu(x);
        y=t.find_dsu(y);
        c[t.q[x].fi].pb(t.q[y].fi);
        c[t.q[y].fi].pb(t.q[x].fi);
        t.union_dsu(x,y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (c[i].size()==1) {dfs(i);exit(0);}
    }
    return 0;
}