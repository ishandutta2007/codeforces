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

ll n, m, i, j, ans, Q, k, l, dp[300001], a[300001], w[300001];
string s;
ll d[8000001], g[8000001];
bool T=0;
vector <pll> c[300001];

void update(ll h,ll l,ll r,ll x,ll k)
{
    if (l==r)
    {
        d[h]+=k;
        g[h]+=k*x;
        return;
    }
    ll w=(l+r)/2;
    if (x<=w) update(h*2,l,w,x,k); else update(h*2+1,w+1,r,x,k);
    d[h]=d[h*2]+d[h*2+1];
    g[h]=g[h*2]+g[h*2+1];
}

ll get(ll h,ll l,ll r,ll x)
{
    //if (T)cout << h << " " << l << "-" << r << "\n";
    if (d[h]==0) return 0;
    if (l==r)
    {
        return min(x/l,d[h]);
    }
    ll w=(l+r)/2;
    if (g[h*2]>=x || d[h*2+1]==0) return get(h*2,l,w,x); else
        return d[h*2]+get(h*2+1,w+1,r,x-g[h*2]);
}

void dfs(ll h,ll k)
{
    ll p1=0, p2=0;
    update(1,0,1000005, w[h], a[h]);
    for (int i = 0; i < c[h].size(); i++)
    {
        dfs(c[h][i].fi, k + c[h][i].se*2);
        ll o = dp[c[h][i].fi];
        if (o > dp[p1]) swap(p1,p2), p1=c[h][i].fi; else
        if (o > dp[p2])p2=c[h][i].fi;
    }
    if (h==1) dp[h]=max(get(1,0,1000005, max(m-k,0ll)),dp[p1]); else dp[h]=max(get(1,0,1000005, max(m-k,0ll)),dp[p2]);
    update(1,0,1000005, w[h], -a[h]);
    //cout << h << " " << dp[h] << " " << dp[p1] << " " << dp[p2] << " " << k*2 << " " << d[1] << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 2; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(mp(i,y));
    }
    dfs(1, 0ll);
    cout << dp[1];
}
/*
10 11
1 2
1 3
1 4
3 4
2 5
2 6
5 6
3 7
4 8
5 9
6 10
*/