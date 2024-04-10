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

using namespace std;

ll n,m,i,u,j,o,k,l,r,a[201],dp[201];
bool t[1000001];
map<ll,ll> mp;
string s,d;

int main()
{
  //freopen("sum.in","r",stdin);
  //freopen("sum.out","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  cin >> s;
  for (i=0;i<n;i++)
  {
   a[i]=s[i]-48;
   if (i==0) dp[i]=a[i]; else dp[i]=dp[i-1]+a[i];
  }
  for (i=2;i<=n;i++)
   if (dp[n-1]%i==0)
   {
    ll p=0,e=0,w=dp[n-1]/i;
    for (j=0;j<n;j++)
     if (dp[j]-p==w) e++,p=dp[j]; else
     if (dp[j]-p>w) break;
     if (e==i) {cout << "YES\n";exit(0);}
   }
  cout << "NO";
  return 0;
}