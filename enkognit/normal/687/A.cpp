#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

ll n, m, k, q, ans, l, r, i, j;
vector <ll> c[100008], v, p;
ll t[200001], us[200001];

void dfs(ll h,ll o)
{
    us[h]=1;
    t[h]=o;
    for (int i = 0; i < c[h].size(); i++)
        if (!us[c[h][i]])
        {
            dfs(c[h][i],1-o);
        }else
        if (t[h]==t[c[h][i]]){cout << -1;exit(0);}
}

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin >> n >> m;
    for (int i = 0; i <= n; i++) t[i]=2;
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    for (int i = 1; i <= n; i++)if (!us[i])dfs(i,0);
    for (int i = 1; i <= n; i++)
        if (t[i]==0) v.pb(i); else if (t[i]==1)p.pb(i);
    cout << p.size() << "\n";
    for (int i = 0; i< p.size(); i++) cout << p[i] << " ";
    cout << "\n";
    cout << v.size() << "\n";
    for (int i = 0; i< v.size(); i++) cout << v[i] << " ";
    cout << "\n";
    return 0;
}