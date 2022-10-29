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

const ll N=1e5*(1e5+1)/2;

ll n,p=0,k,b,m,i,j,o,l,ans,x,y,q,a[1001],d[11][1002],dp[10001];
vector <ll> v;
string s;

bool isans(ll x,ll y)
{
 bool u=1;
 for (int i=0;i<m;i++)
  if (d[i][x]<d[i][y]) {u=0;break;}
 return u;
}

int main()
{
  //freopen("half.in","r",stdin);
  //freopen("half.out","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen("input1.txt","r",stdin);
  //freopen("output1.txt","w",stdout);
  cin >> n >> m;
  for (i=0;i<m;i++)
  {
   for (j=0;j<n;j++) {cin >> a[j];d[i][a[j]]=j;}
  }
  //dp[0]=1;
  for (i=0;i<n;i++)
  {
   ll p=0;
   for (j=0;j<i;j++)
    if (dp[j]>p)
     if (isans(a[i],a[j])) {p=max(dp[j],p);}
   dp[i]=p+1;
  }
  ll p=0;
  for (i=0;i<n;i++) p=max(p,dp[i]);
  cout << p;
  return 0;
}