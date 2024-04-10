#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define pll pair<ll,ll>
#define y1 Enkognit
#define fi first
#define se second
#define pld pair<ld,ld>

using namespace std;

const ll MOD=1000000007;

ll l, r, n, m, k, x, y, a[1000001], dp[1000001][2];
bool tt[1000001];
vector <ll> c[200001];

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h,l%=MOD;
        h*=h;
        h%=MOD;
        r/=2;
    }
    return l;
}

vector<pll> v;

void solve1()
{
    ll p=0, o=0;
    for (int i = 1; i <= n; i++)
        if (c[i].size()==n-1) p++; else
        if (c[i].size()==n-2) o++;
    if (p) cout << x+y*(n-2); else
    cout << y*(n-1);
}

void dfs(int h)
{
    tt[h]=1;
    ll k=0, sum=0;
    vector<pll> v;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]])
        {
            k++;
            dfs(c[h][i]);
            sum+=min(dp[c[h][i]][0],dp[c[h][i]][1]);
            v.pb(mp(dp[c[h][i]][1]-dp[c[h][i]][0], dp[c[h][i]][0]));
        }
    sort(v.begin(),v.end());
    if (v.size()==0)
    {
        dp[h][1]=y;
        dp[h][0]=1e18;
        return;
    }
    dp[h][1]=sum+y;
    dp[h][1]=min(dp[h][1],sum+max(0ll,v[0].fi)+x);
    if (v.size()==1)
    {
        dp[h][0]=1e18;
        //cout << h << " : " << dp[h][0] << " " << dp[h][1] << "\n";
        return;
    }
    dp[h][0]=sum+max(0ll,v[0].fi)+max(0ll,v[1].fi)+x*2-y;
    //cout << h << " : " << dp[h][0] << " " << dp[h][1] << "\n";
}

void solve2()
{
    dfs(1);
    cout << min(dp[1][1],dp[1][0])-y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x >> y;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    if (n==2) {cout << x;exit(0);}
    if (x>=y)
    {
        solve1();
    }else
    {
        solve2();
    }
    return 0;
}