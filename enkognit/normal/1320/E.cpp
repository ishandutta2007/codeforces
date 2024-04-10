#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("-avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

//const ll MOD=1e9+7;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, q, mx, ans=0, j, kl, k, x, y, TT, T, len, sm=0, hh[200001], dp[200001];
ll in[200001], out[200001];
bool tt[200001];
ll bn[200001][22];
vector<ll> c[200001];
vector<ll> g[200001];
vector<ll> v;
vector<pll> vv;
vector<pll> virus;
string d;

void dfs(int h,int p=0)
{
    bn[h][0]=p;
    T++;
    in[h]=T;
    if (p==0) hh[h]=0; else hh[h]=hh[p]+1;
    for (int i = 1; i < 21; i++) bn[h][i]=bn[bn[h][i-1]][i-1];

    for (int i = 0; i < c[h].size(); i++)
        if (p!=c[h][i])
            dfs(c[h][i],h);
    T++;
    out[h]=T;
}

bool is_ancestor(int x,int y)
{
    return (in[x]<=in[y] && out[x]>=out[y]);
}

ll get_lca(int x,int y)
{
    if (is_ancestor(x,y)) return x;
    if (is_ancestor(y,x)) return y;
    for (int i = 20; i > -1; i--)
        if (!is_ancestor(bn[x][i],y)) x=bn[x][i];
    if (!is_ancestor(x,y)) x=bn[x][0];
    return x;
}

ll get_dist(int x,int y)
{
    ll p=get_lca(x,y);
    return hh[x]+hh[y]-2*hh[p];
}

void dfs1(int h,int p=0)
{
    //cout << h << "\n";
    //system("pause");
    for (int i = 0; i < g[h].size(); i++)
        if (p!=g[h][i])
        {
            dfs1(g[h][i],h);
            if (dp[g[h][i]]!=0 && dp[g[h][i]]!=dp[h])
            {
                if (dp[h]==0) dp[h]=dp[g[h][i]]; else
                {
                    ll p=(get_dist(virus[dp[h]-1].fi,h)+virus[dp[h]-1].se-1)/virus[dp[h]-1].se;
                    ll u=(get_dist(virus[dp[g[h][i]]-1].fi,h)+virus[dp[g[h][i]]-1].se-1)/virus[dp[g[h][i]]-1].se;
                    if ((p>u || p==u && dp[h]>dp[g[h][i]])) dp[h]=dp[g[h][i]];
                }
            }
        }
}

void dfs2(int h,int p=0)
{
   //cout << h << "\n";
    if (p!=0)
    {
        if (dp[p]!=0 && dp[h]!=dp[p])
            {
                if (dp[h]==0) dp[h]=dp[p]; else
                {
                    ll z=(get_dist(virus[dp[h]-1].fi,h)+virus[dp[h]-1].se-1)/virus[dp[h]-1].se;
                    ll u=(get_dist(virus[dp[p]-1].fi,h)+virus[dp[p]-1].se-1)/virus[dp[p]-1].se;
                    if ((z>u || z==u && dp[h]>dp[p])) {dp[h]=dp[p];}
                }
            }
    }
    for (int i = 0; i < g[h].size(); i++)
        if (p!=g[h][i])
        {
            dfs2(g[h][i],h);
        }
}

void solve()
{
    //cout << "------\n";
    cin >> n >> m;
    vector<pll> v;
    vv.clear();
    virus.clear();

    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (!tt[x])
        {
            g[x].clear();
            vv.pb(mp(in[x],x));
            tt[x]=1;
            dp[x]=0;
        }
        virus.pb(mp(x,y));
        dp[x]=i;
        v.pb(mp(in[x],x));
    }
    vector<ll> que;
    for (int i = 1; i <= m; i++)
    {
        ll x;
        cin >> x;
        if (!tt[x])
        {
            tt[x]=1;
            dp[x]=0;
            vv.pb(mp(in[x],x));
            g[x].clear();
        }
        que.pb(x);
        v.pb(mp(in[x],x));
    }
    //cout << "\n";
    sort(all(v));
    //for (int i = 0; i < v.size(); i++) cout << v[i].fi << "-" << v[i].se << "\n";

    for (int i = 0; i < v.size()-1; i++)
    {
        ll p=get_lca(v[i].se,v[i+1].se);
        if (!tt[p])
        {
            tt[p]=1;
            dp[p]=0;
            vv.pb(mp(in[p],p));
            g[p].clear();
        }
    }
    if (!tt[1]) vv.pb(mp(in[1],1)), tt[1]=1, g[1].clear(), dp[1]=0;
    sort(all(vv));

    vector<ll> st;
    st.pb(vv[0].se);

    for (int i = 1; i < vv.size(); i++)
    {
        while (!is_ancestor(st.back(),vv[i].se)) st.pop_back();
        g[st.back()].pb(vv[i].se);
        g[vv[i].se].pb(st.back());
        //cout << st.back() << " " << vv[i].se << "\n";
        st.pb(vv[i].se);
    }

    dfs1(1);
    dfs2(1);
    for (int i = 0; i < que.size(); i++) cout << dp[que[i]] << " ";
    cout << "\n";
    for (int i = 0; i < vv.size(); i++) tt[vv[i].se]=0, g[vv[i].se].clear(), dp[vv[i].se]=0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll nn;
    in[0]=-1;out[0]=1e9;
    cin >> nn;
    for (int i = 1; i < nn; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    dfs(1);
    cin >> q;
    while (q--)
    {
        solve();
    }
    return 0;
}