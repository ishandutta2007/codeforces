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

ll n,m,k,l,r=0,i,j,w,x,y,z;
ll a[1001];
string s;

//struct thll{ll fi,se,th;};

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n >> m;
  cin >> s;
  for (i=0;i<n;i++)
  {
   a[i+1]=s[i]-96;
  }
  sort(a+1,a+n+1);
  k+=a[1];
  x=a[1];
  l++;
  if (l==m) {cout << k;exit(0);}
  for (i=2;i<=n;i++)
  {
   if (a[i]-x>=2) {x=a[i];k+=a[i];l++;if (l==m) {cout << k;exit(0);}}
  }
  cout << -1;
  return 0;
}