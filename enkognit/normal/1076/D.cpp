#include <bits/stdc++.h>

#define ll long long
#define fi first
#define fr front()
#define se second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define ld long double
#define pll pair<ll,ll>
#define pii pair<int,int>
//#define pi 3.14159265358979323846

using namespace std;

ll n, m, k, j, o, l, r;
ll a[500001];
bool t[500001], tt[500001];
vector <pair<pll,ll> > c[300001];
vector <ll> ans;
ll dist[300001];

bool fl1=0, fl2=0;

void dij(ll e)
{
    set<pll> q;
    for (int i = 1; i <= n; i++) dist[i]=1e18;
    dist[e]=0;
    q.insert(mp(dist[e],e));
    while (q.size())
    {
        pll p=*q.begin();
        q.erase(q.begin());
        ll x=p.se, h=p.fi;
        for (int i = 0; i < c[x].size(); i++)
            if (dist[c[x][i].fi.fi]>dist[x]+c[x][i].fi.se)
            {
                q.erase(mp(dist[c[x][i].fi.fi],c[x][i].fi.fi));
                dist[c[x][i].fi.fi]=dist[x]+c[x][i].fi.se;
                q.insert(mp(dist[c[x][i].fi.fi],c[x][i].fi.fi));
            }
    }
}

void dfs(ll h,ll p)
{
    t[h]=1;
    for (int i = 0; i < c[h].size(); i++)
    {
        if (!t[c[h][i].fi.fi])
        {
            if (dist[h]+c[h][i].fi.se==dist[c[h][i].fi.fi]) dfs(c[h][i].fi.fi,h);
        } else
        if (c[h][i].fi.fi!=p)tt[c[h][i].se]=1;
    }
}

void dfs1(ll h)
{
    t[h]=1;
    if (ans.size()==k)
    {
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        exit(0);
    }
    for (int i = 0; i < c[h].size(); i++)
        if (!t[c[h][i].fi.fi] && !tt[c[h][i].se])
        {
            if (ans.size()==k)
            {
                cout << ans.size() << "\n";
                for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
                exit(0);
            }
            ans.pb(c[h][i].se);
            dfs1(c[h][i].fi.fi);
        }
}

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        ll x, y, h;
        cin >> x >> y >> h;
        c[x].pb(mp(mp(y,h),i+1));
        c[y].pb(mp(mp(x,h),i+1));
    }
    dij(1);
    for (int i = 1; i <= n; i++) {t[i]=0;}
    //cout << "\n";
    dfs(1,-1);
    //for (int i = 1; i <= m; i++) cout << tt[i] << " ";
    //cout << "\n";
    for (int i = 1; i <= n; i++) t[i]=0;
    dfs1(1);
    //cout << k << "\n";
    cout << min((ll)ans.size(),k) << "\n";
    for (int i = 0; i < min((ll)ans.size(),k); i++) cout << ans[i] << " ";
    return 0;
}
/*

*/