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

ll n,m,i,j,k,l,ans,a[200001],dp[200001],qp[200001];
ll b[200001];
vector <ll> c[200001];
map <ll,ll> t,tt;


pll dfs(ll h)
{
 for (int i=0;i<c[h].size();i++)
  if (!t[c[h][i]])
 {
  t[c[h][i]]=1;
  pll l=dfs(c[h][i]);
  dp[h]+=l.fi;
  qp[h]+=l.se;
 }
 return mp(dp[h]+a[h],dp[h]+a[h]+qp[h]);
}

void dfs2(ll h,ll k,ll ch)
{
 ans=max(qp[h]+k,ans);
 b[h]=qp[h]+k;
 for (int i=0;i<c[h].size();i++)
  if (!tt[c[h][i]])
 {
  tt[c[h][i]]=1;
  dfs2(c[h][i],k+ch+qp[h]-qp[c[h][i]]-dp[c[h][i]]-a[c[h][i]]+dp[h]-dp[c[h][i]]-a[c[h][i]]+a[h],
       ch+dp[h]-dp[c[h][i]]-a[c[h][i]]+a[h]);
 }
}

int main()
{
  //freopen("cipher.in","r",stdin);
  //freopen("cipher.out","w",stdout);
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=1;i<=n;i++) cin >> a[i];
  for (i=0;i<n-1;i++)
  {
   ll x,y;
   cin >> x >> y;
   c[x].pb(y);
   c[y].pb(x);
  }
  t[1]=1;
  for (i=0;i<c[1].size();i++)
  {
   t[c[1][i]]=1;
   pll l=dfs(c[1][i]);
   t[c[1][i]]=0;
   dp[1]+=l.fi;
   qp[1]+=l.se;
  }
  //for (i=1;i<=n;i++) cout << qp[i] << "-" << dp[i] << "\n";
  tt[1]=1;
  ans=qp[1];
  dfs2(1,0,0);
  cout << ans << "\n";
  //for (i=1;i<=n;i++) cout << b[i] << " ";
  return 0;
}