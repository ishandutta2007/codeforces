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

ll n,i,j,p,u,x,m,l=0,k,a[200001];
string s,d;

int main()
{
  //freopen("ledtest.in","r",stdin);
  //freopen("ledtest.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  cin >> s;
  cin >> d;
  for (i=0;i<n-1;i++)
  {
   if (s[i]!=d[i])
   {
    if (s[i+1]!=d[i+1] && s[i]!=s[i+1]) {l++;
    s[i+1]=d[i+1];}else
    l++;
   }
  }
  if (s[n-1]!=d[n-1]) l++;
  cout << l;
  return 0;
}