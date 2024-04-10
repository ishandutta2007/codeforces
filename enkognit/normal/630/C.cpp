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

ll n,m,k,l,r,i,j,w,x,y,p,b[200001],c[200001];
bool t;
string s,d;

struct thll{ll fi,se,th;};

thll a[200001];

bool comp(thll x,thll y)
{
 if (x.fi<y.fi) return 1; else return 0;
}

int main()
{
  //freopen("division.in","r",stdin);
  //freopen("division.out","w",stdout);
  cin >> n;
  for (i=1;i<=n;i++)
  {
   k+=pow(2,i);
  }
  cout << k;
  return 0;
}