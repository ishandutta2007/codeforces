#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1000000007;

ll n, w, m, i, j, Q, k, l, T, a[300001], rad[100001];
string s, ans;
vector <ll> c[100001];
bool tt[100001];

ll dfs(ll h)
{
    tt[h]=1;
    ll p1=0, p2=0;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]])
        {
            ll o=dfs(c[h][i]);
            if (o>p1) swap(p1,p2), p1=o; else
            if (o>p2) p2=o;
        }
    w=max(p1+p2, w);
    return p1+1;
}

void dfs1(ll h)
{
    tt[h]=1;
    if (rad[T]>rad[h]) T=h;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]])
        {
            dfs1(c[h][i]);
        }
}

bool comp(ll x,ll y)
{
    return rad[x]>rad[y];
}

int main()
{
    //freopen("pisa.in","r",stdin);
    //freopen("pisa.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    rad[T]=1e18;
    w=0;
    vector <ll> v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) tt[j]=0;
        rad[i]=dfs(i)-1;
    }
    for (int i = 1; i <= n; i++) tt[i]=0;

    for (int i = 1; i <= n; i++)
        if (!tt[i])
        {
            T=0;
            dfs1(i);
            v.pb(T);
        }
    vector <pll> ans;
    sort(v.begin(),v.end(),comp);
    //cout << rad[1] << "\n";
    //cout << v[0] << " ";
    for (int i = 1; i < v.size(); i++)
    {
        ans.pb(mp(v[0],v[i]));
        w=max(w, rad[v[0]]+1+rad[v[i]]);
        if (i>1) w=max(w, rad[v[1]]+2+rad[v[i]]);
    }
    cout << w << "\n";
    for (int i = 0; i < ans.size(); i++) cout << ans[i].fi << " " << ans[i].se << "\n";
}