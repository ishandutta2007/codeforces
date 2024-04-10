#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pii pair<int,int>
#define y1 Enkognit
#define sqr(a) ((a)*(a))
#define all(a) a.begin(),a.end()

using namespace std;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

const ll md1=1e9+7, md2=998244357, md3=rnd()%(ll)(1e8), p1=31, p2=37, p3=41;

//template <typename T>
//using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, l, r, pp, mx=-1e18, x, y, ans, n1, n2, n3, pr[200001];
pll mxa[1000001];
string s;
vector<ll> c[200001];
vector<pll> dp[200001];

void dfs1(int h,int p=-1)
{
    dp[h].resize(c[h].size(),mp(0,0));
    mxa[h]=mp(0,h);
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]==p) pr[h]=i; else
        {
            dfs1(c[h][i],h);
            dp[h][i]=mp(mxa[c[h][i]].fi+1,mxa[c[h][i]].se);
            mxa[h]=((mxa[h].fi<dp[h][i].fi)?dp[h][i]:mxa[h]);
        }
    //cout << h << " : \n";
}

void dfs2(int h,int p=-1)
{
    vector <pair<pll,ll> > v;
    v.resize(2,mp(mp(-1,0),-1));
    v[0]=mp(mp(0,h),-1);
    for (int i = 0; i < c[h].size(); i++)
    {
        pair<pll,ll> o=mp(dp[h][i],c[h][i]);
        for (int j = 0; j < 2; j++)
            if (v[j].fi.fi<o.fi.fi) swap(o,v[j]);
    }
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dp[c[h][i]][pr[c[h][i]]]=mp((c[h][i]==v[0].se?v[1].fi.fi:v[0].fi.fi)+1,(c[h][i]==v[0].se?v[1].fi.se:v[0].fi.se));
            dfs2(c[h][i],h);
        }
}

int main()
{
    //freopen("loan.in","r",stdin);
    //freopen("loan.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    dfs1(1);
    dfs2(1);
    for (int i = 1; i <= n; i++)
        if (c[i].size()>1)
        {
            vector<pll> v;
            v.resize(3,mp(-1,-1));
            v[0]=mp(0,i);
            //cout << i << " : \n";
            for (int j = 0; j < c[i].size(); j++)
            {
                pll o=dp[i][j];
                //cout << " " << c[i][j] << " - " << o.se << " : " << o.fi << "\n";
                for (int u = 0; u < 3; u++) if (o.fi>v[u].fi) swap(o,v[u]);
            }
            if (ans<v[0].fi+v[1].fi+v[2].fi) ans=v[0].fi+v[1].fi+v[2].fi, n1=v[0].se, n2=v[1].se, n3=v[2].se;
        }
    cout << ans << "\n" << n1 << " " << n2 << " " << n3 << "\n";
}