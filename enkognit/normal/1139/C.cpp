#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1e9+7;

ll n, i, j, m, ans, k, q, l, r, z, a[500001];
pll b[500001];
vector <ll> v;
vector <ll> c[100001];
bool t[100001];
string s;

void dfs(ll h)
{
    t[h]=1;
    k++;
    for (int i = 0; i < c[h].size(); i++) if (!t[c[h][i]])dfs(c[h][i]);
}

int main()
{
    //freopen("robots.in","r",stdin);
    //freopen("robots.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        ll x, y, h;
        cin >> x >> y >> h;
        if (!h)
        {
            c[x].pb(y);
            c[y].pb(x);
        }
    }
    ll o=0;
    for (int i = 1; i <= n; i++)
        if (!t[i])
        {
            k=0, q=1;
            dfs(i);
            for (int j = 0; j < m; j++) q*=k,q%=MOD;
            o+=q;
            o%=MOD;
        }
    ll p=1;
    for (int i = 0; i < m; i++) p*=n,p%=MOD;
    ll ans=p-o;
    if (ans<0) ans=MOD+ans;
    cout << ans;
    return 0;
}