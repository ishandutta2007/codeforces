#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fr front()
#define sqr(a) ((a)*(a))
#define y1 Enkognit

using namespace std;

ll n, m, l, r, x, y, a[300001], hh[200001], ans, sum, T=0, qua1[200001], qua0[200001];
vector <ll> c[200001], d[200001];
int t1[200001], t0[200001];

void dfs1(ll h)
{
    t1[h]=1;
    T++;
    for (int i = 0; i < c[h].size(); i++)
        if (!t1[c[h][i]])
        {
            dfs1(c[h][i]);
        }
}

void dfs12(ll h)
{
    t1[h]=2;
    qua1[h]=T;
    for (int i = 0; i < c[h].size(); i++)
        if (t1[c[h][i]]==1)
        {
            dfs12(c[h][i]);
        }
}

void dfs0(ll h)
{
    t0[h]=1;
    T++;
    for (int i = 0; i < d[h].size(); i++)
        if (!t0[d[h][i]])
        {
            dfs0(d[h][i]);
        }
}

void dfs02(ll h)
{
    t0[h]=2;
    qua0[h]=T;
    for (int i = 0; i < d[h].size(); i++)
        if (t0[d[h][i]]==1)
        {
            dfs02(d[h][i]);
        }
}

int main()
{
    //freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        ll x, y, h;
        cin >> x >> y >> h;
        if (h==0)
        {
            d[x].pb(y);
            d[y].pb(x);
        }
         else
        {
            c[x].pb(y);
            c[y].pb(x);
        }
    }

    for (int i = 1; i <= n; i++)
        if (!t1[i])
        {
            T=0;
            dfs1(i);
            ans+=T*(T-1);
            dfs12(i);
        }

    for (int i = 1; i <= n; i++)
        if (!t0[i])
        {
            T=0;
            dfs0(i);
            ans+=T*(T-1);
            dfs02(i);
        }

    for (int i = 1; i <= n; i++)
    {
        ans+=(qua1[i]-1)*(qua0[i]-1);
        //cout << qua1[i] << " " << qua0[i] << "\n";
    }
    cout << ans;
    return 0;
}