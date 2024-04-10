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

using namespace std;

ll n,k,m,i,j,o,l,ans,x,y,a[1000001];
vector<ll> b[1000001];

int main()
{
  //freopen("H.in","r",stdin);
  //freopen("H.out","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  for (int i=2;i<=1e5;i++)
  {
   int x=i;
   while (x<=(int)1e6)
   {
    b[x].pb(i);
    x+=i;
   }
  }
  cin >> n;
  a[0]=1;
  for (i=0;i<n;i++)
  {
   cin >> x;
   for (j=0;j<b[x].size();j++)
   {
    ll o=b[x].size()-j-1;
    a[b[x][o]]=(a[b[x][o]]+a[b[x][o]-1])%((ll)1e9+7);
   }
   a[1]=(a[0]+a[1])%((ll)1e9+7);
  }
  for (i=1;i<=n;i++) ans=(ans+a[i])%(ll)(1e9+7);
  cout << ans;
  return 0;
}