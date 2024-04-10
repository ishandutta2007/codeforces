#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pu push
#define ld long double
#define pld pair<ld,ld>
#define y1 Enkognit
//#define {cout.flush()} {fflush(stdout)}

using namespace std;

const ll MOD=1e9;

ll n, m, ans, k, l, ls, r, i, j, a[300005], kol[300005];
vector<ll> c[300005];

void dfs0(ll h)
{
    ls+=(c[h].size()==0);
    kol[h]=(c[h].size()==0);
    if (a[h] && c[h].size()) kol[h]=5e18;
    for (int i = 0; i < c[h].size(); i++)
    {
        dfs0(c[h][i]);
        if (a[h])kol[h]=min(kol[h], kol[c[h][i]]); else kol[h]+=kol[c[h][i]];
    }
}

void dfs(ll h,ll k)
{
    //cout << h << " " << k << " " << ls << "\n";
    if (c[h].size()==0) ans=max(ans,ls-k);
    for (int i = 0; i < c[h].size(); i++)
    {
        dfs(c[h][i], k+(!a[h])*(kol[h]-kol[c[h][i]]));
    }
}

int main()
{
    //freopen("cipher.in","r",stdin);
    //freopen("cipher.out","w",stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("rope.in","r",stdin);
    //freopen("rope.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        c[x].pb(i);
    }
    dfs0(1);
    dfs(1,0);
    cout << ans;
    return 0;
}