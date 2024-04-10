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

ll n, m, i, j, k, l, r, p, a[500001];
pll b[500001];
string s, d;
bool t[500001], tt[500001];
vector <ll> v, c[500001];

void dfs(ll h)
{
    tt[h]=1;
    //cout << h << "\n";
    ll a=0, b=0;
    for (int i = 0; i < c[h].size(); i++)
    {
        dfs(c[h][i]);
        a++;
        b+=t[c[h][i]];
    }
    //cout << h << " " << a << " " << b << "\n";
    if (t[h] && a==b && h!=p)v.pb(h);
}

int main()
{
    //freopen("robots.in","r",stdin);
    //freopen("robots.out","w",stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    p=0;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (x==-1) p=i; else
        c[x].pb(i);
        t[i]=y;

    }
    dfs(p);
    if (v.size()==0) cout << -1;
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";

    return 0;
}