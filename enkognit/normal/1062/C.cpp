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

using namespace std;

ll n,m,i,j,k,l=0,x,y,h=1,r,o,p=0;
string s;
map <ll,ll> f;
ll t[200002];

int main()
{
  //freopen("div7.in","r",stdin);
  //freopen("div7.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  cin >> s;
  for (i=1;i<=100005;i++) f[i]=(f[i-1]*2+1)%((ll)(1e9+7));
  for (i=0;i<n;i++)
  {
   t[i+1]=t[i]+(s[i]=='1');
  }
  for (i=0;i<m;i++)
  {
   ll x,y;
   cin >> x >> y;
   ll l=t[y]-t[x-1];
   cout << (f[y-x+1]-f[y-x+1-l]+(ll)1e9+7)%(ll)(1e9+7) << "\n";
  }
  return 0;
}