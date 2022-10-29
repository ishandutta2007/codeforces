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

ll n,i,j,p,x,y,m,l=0,l1,r,k=1e9;string s;
map <char,ll> c;

int main()
{
  //freopen("ledtest.in","r",stdin);
  //freopen("ledtest.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  m=n*(n+1)/2;
  for (i=2;i<n;i++) if (m%i==0)
  {
   cout << "Yes\n";
   cout << "1 " << i << "\n";
   cout << n-1 << " ";
   for (int j=1;j<i;j++) cout << j << " ";
   for (int j=i+1;j<=n;j++) cout << j << " ";
   exit(0);
  }
  cout << "No";
  return 0;
}