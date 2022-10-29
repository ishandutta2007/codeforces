#include <bits/stdc++.h>
#pragma GCC optimize("-g")
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

const ll MOD=1e9+7;

ll n, m, i, j, k, l, T, r, b[100001], o, an=0, hh[100001];
ll ans=0;
vector <int> c[100001];
vector <pll> p, v, q;
bool tt[100001];

ll gcd(ll a,ll b)
{
    if (a==0||b==0) return a+b;
    return __gcd(a,b);
}

void dfs(int h, vector <pll> v)
{
    tt[h]=1;
    vector <pll> p;
    p.pb(mp(b[h],1));
    for (int i = 0; i < v.size(); i++)
    {
        ll o=gcd(v[i].fi,b[h]);
        p.pb(mp(o,v[i].se));
    }
    v.clear();
    sort(p.begin(),p.end());
    v.pb(p[0]);
    for (int i = 1; i < p.size(); i++) if (p[i].fi!=p[i-1].fi) v.pb(p[i]); else v[v.size()-1].se+=p[i].se;
    for (int i = 0; i < v.size(); i++) ans+=(v[i].fi%MOD*v[i].se)%MOD, ans%=MOD;
    //p.clear();
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]])
        {
            dfs(c[h][i], v);
        }
    //cout << h << "\n";
    //for (int i = 0; i < q.size(); i++) {cout << q[i].fi << " " << q[i].se << "\n";}
}

bool comp(ll a,ll b)
{
    return hh[a]>hh[b];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {cin >> b[i];}
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    dfs(1,{});
    cout << ans;
    return 0;
}