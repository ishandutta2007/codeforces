#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("popcnt")
#include <random>
#include <time.h>
#define ll long long
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

ll n, T, m, ans[200005], hh[200005], k, in[200005], out[200005], bn[200005][20], kl[200005], kol[200005];
vector<ll> c[200005], g[200005], gg[200005];
bool tt[200005];

void dfs(int h,int p=n+2)
{
    hh[h]=hh[p]+1;
    bn[h][0]=p;
    in[h]=++T;
    for (int i = 1; i < 17; i++)
        bn[h][i]=bn[bn[h][i-1]][i-1];
    kol[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs(c[h][i], h);
            kol[h]+=kol[c[h][i]];
        }
    out[h]=++T;
    //cout << h << " " << in[h] << " " << out[h] << " " << c[h].size() << "\n";
}

bool is_ancestor(int x,int y)
{
    return in[x]<=in[y] && out[x]>=out[y];
}

ll lca(ll x,ll y)
{
    if (is_ancestor(x,y)) return x;
    if (is_ancestor(y,x)) return y;
    for (int i = 16; i > -1; i--)
        if (!is_ancestor(bn[x][i], y)) x=bn[x][i];
    return bn[x][0];
}

void dfs2(int h)
{
    tt[h]=1;
    kl[h]=1;
    for (int i = 0; i < g[h].size(); i++)
        if (!tt[g[h][i]])
        {
            dfs2(g[h][i]);
            //cout << h << " " << kl[h] << " " << kl[g[h][i]] << "\n";
            ans[0]+=kl[h]*kl[g[h][i]];
            kl[h]+=kl[g[h][i]];
        }
}

void dfs3(int h)
{
    tt[h]=1;
    kl[h]=1;
    for (int i = 0; i < gg[h].size(); i++)
        if (!tt[gg[h][i]])
        {
            dfs3(gg[h][i]);
            //cout << h << " " << kl[h] << " " << kl[g[h][i]] << "\n";
            kl[h]+=kl[gg[h][i]];
        }
}

void solve()
{
    cin >> n;

    out[n+2]=1e9;

    for (int i = 0; i <= n; i++)
        in[i]=0, tt[i]=0, ans[i]=0, out[i]=0, c[i].clear(), g[i].clear(), gg[i].clear(),  kl[i]=0, kol[i]=0, hh[i]=0, ans[i]=0;


    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
        if (x!=0 && y!=0)
        {
            g[x].pb(y);
            g[y].pb(x);
        }
        if (x!=1 && y!=1)
        {
            gg[x].pb(y);
            gg[y].pb(x);
        }
    }

    ll kl1=0, kl2=0;

    for (int i = 0; i < n; i++)
    {
        if (c[i].size()==1) kl1++; else
        if (c[i].size()==2) kl2++;
    }

    for (int i = 1; i < n; i++)
        if (!tt[i]) dfs2(i);

    for (int i = 0; i <= n; i++) tt[i]=0;

    dfs3(0);

    ll o=1;

    for (int i = 0; i < gg[0].size(); i++)
    {
        //cout << gg[0][i] << " " << kl[gg[0][i]] << "\n";
        ans[1]+=o*kl[gg[0][i]];
        o+=kl[gg[0][i]];
    }

    dfs(0);

    //cout << kol[x] << "\n";

    ll x=0, y=1, p=lca(0, 1), e=0;
    for (int i = 0; i < c[0].size(); i++)
        if (is_ancestor(c[0][i], 1))
        {
            e=c[0][i];
            break;
        }
    bool ttt=0;
    for (int i = 2; i < n && !ttt; i++)
    {
        if (x==p) swap(x, y);

        //cout << "! " << i << " " << x << " " << y << "\n";

        if (!(is_ancestor(p, i) && (is_ancestor(i, x) || is_ancestor(i, y))))
        {
            if (y==p)
            {
                ll o1=kol[x], o2=n-kol[e];
                //cout << " " << o1 << " " << o2 << "\n";
                if (is_ancestor(x, i))
                {
                    o1-=kol[i];
                    x=i;
                } else
                if (is_ancestor(y, i))
                {
                    for (int j = 0; j < c[y].size(); j++)
                        if (is_ancestor(c[y][j], i))
                        {
                            if (is_ancestor(c[y][j], x))
                            {
                                ttt=1;
                                break;
                            }
                        }
                    if (!ttt) o2-=kol[i];
                    y=i;
                } else
                if (is_ancestor(i, y))
                {
                    ll p=n;
                    for (int j = 0; j < c[i].size(); j++)
                        if (is_ancestor(c[i][j], y))
                        {
                            p-=kol[c[i][j]];
                            e=c[i][j];
                            break;
                        }
                    o2-=p;
                    y=i;
                }else
                {
                    ll o=1;
                    assert(o==0);
                }
                ans[i]=o1*o2;
            } else
            {
                ll o1=kol[x], o2=kol[y];
                if (is_ancestor(x, i)) o1-=kol[i], x=i; else
                if (is_ancestor(y, i)) o2-=kol[i], y=i; else
                {
                    ttt=1;
                }
                ans[i]=o1*o2;
            }
        }

        p=lca(x, y);
    }

    if (kl1==2 && kl2==n-2) ans[n]=1;

    for (int i = 0; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
1000000000000000 4523 3
456 23
4562 78
456239 456
*/