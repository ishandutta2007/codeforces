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

ll n,m,i,j,w,p;
bool t;
string s,d;

//struct thll{ll fi,se,th;};

double a[200001],x,k,l,r;



int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n >> m;
  for (i=0;i<m;i++)
  {
   cin >> x >> a[i];
   k+=x;
  }
  k*=n;
  n--;l=n*(n+1)/2;
  r=n/2*(n/2+1);
  if (n%2==1) r+=(n+1)/2;
  for (i=0;i<m;i++)
  {
   if (a[i]>0) k+=l*a[i]; else k+=r*a[i];
  }
  cout.precision(10);
  cout <<fixed<< k/(n+1);
  return 0;
}