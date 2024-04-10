#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define leng length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;
ll n, m, k, ans, q, l, r, i, j, kol[200005], sum[200005];
bool t[1000001];
vector <ll> c[200005];
ll d[2000005];

void dfs(ll h)
{
    sum[h]=1;
    kol[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (!sum[c[h][i]])
        {
            dfs(c[h][i]);
            kol[h]+=kol[c[h][i]];
            sum[h]+=sum[c[h][i]]+kol[c[h][i]];
        }
}

void dfs2(ll h,ll kl,ll sm)
{
    t[h]=1;
    ans=max(sm,ans);
    for (int i = 0; i < c[h].size(); i++)
        if (!t[c[h][i]])
        {
            ll plk=kol[h]-kol[c[h][i]], pls=sum[h]-sum[c[h][i]]-kol[c[h][i]];
            dfs2(c[h][i],kl+plk,sm+pls+kl+plk);
        }
}

int main()
{
  //freopen("strangestring.in","r",stdin);
  //freopen("strangestring.out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++)
  {
      ll x, y;
      cin >> x >> y;
      c[x].pb(y);
      c[y].pb(x);
  }
  dfs(1);
  //cout << sum[1] << "\n";
  dfs2(1,0,0);
  cout << ans+1;
  return 0;
}
/*for (int i = 0; i < v1.size(); i++)
  {
      while (z<v0.size() && v0[z].se<v1[i].fi) z++;
      if (z==v0.size()) break;
      if (v1[i].se>=v0[z].se && v0[z].fi>=v1[z].fi) {cout << "NO\n";exit(0);}
  }*/