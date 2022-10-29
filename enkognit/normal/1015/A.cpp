#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

ll n,m,k,l=0,r,i,j,w,x,y,a[100001];
bool t[10001];
vector <int> b;

int main()
{
  //freopen("msched.in","r",stdin);
  //freopen("msched.out","w",stdout);
  cin >> n >> m;
  for (i=0;i<n;i++)
  {
   cin >> x >> y;
   for (j=x;j<=y;j++) t[j]=1;
  }
  for (i=1;i<=m;i++) {if (!t[i]) {l++;b.pb(i);}}
  cout << l << "\n";
  for (i=0;i<l;i++) cout << b[i] << " ";
  return 0;
}