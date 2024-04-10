#include <bits/stdc++.h>
#include <cstdlib>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define el endl
#define pu push
#define sqr(a) ((a)*(a))
#define pld pair<long double,long double>
#define ld long double

using namespace std;

ld PI=3.14159265359, sec_clock=1e8;

ll n, m, l, r, k, h, i, j, T, ans, d;
//ll a[500001], b[500001];
vector <ll> v, c[200001];
bool t[200001], tt[200001];
queue <ll> q;

void dfs(ll h)
{
    t[h]=1;
    if (h!=1)
    for (int i = 0; i < c[h].size(); i++)
        if (!t[c[h][i]])
        {
            dfs(c[h][i]);
        }
}

int main()
{
    //freopen("sum.in","r",stdin);
    //freopen("sum.out","w",stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m >> d;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    if (c[1].size()<d) {cout << "NO\n";exit(0);}
    t[h]=1;
    for (int i = 0; i < c[1].size(); i++)
        if (!t[c[1][i]]) {tt[c[1][i]]=1;v.pb(c[1][i]);dfs(c[1][i]);}
    if (v.size()>d) {cout << "NO\n";exit(0);}
    for (int i = 0; i < c[1].size(); i++)
        if (!tt[c[1][i]] && v.size()<d) {v.pb(c[1][i]);tt[c[1][i]]=1;}
    for (int i = 1; i <= n; i++) t[i]=0;
    t[1]=1;
    cout << "YES\n";
    for (int i = 0; i < d; i++) {cout << "1 " << v[i] << "\n";q.push(v[i]);t[v[i]]=1;}
    while (!q.empty())
    {
        ll h=q.fr;
        q.pop();
        for (int i = 0; i < c[h].size(); i++) if (!t[c[h][i]]) {t[c[h][i]]=1;cout << h << " " << c[h][i] << "\n";q.push(c[h][i]);}
    }
    //cout.precision(9);
    //cerr << "Time: " <<fixed<< clock()/sec_clock << "\n";
    return 0;
}