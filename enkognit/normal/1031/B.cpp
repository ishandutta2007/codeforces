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

ll n,m,i,j,x,y,z,k,l=0,o,p,a[100003],c[100003],d[100003];

void rec(ll* b,ll k)
{
 if (k==n-1) {cout << "YES\n";for (int j=0;j<n;j++) cout << b[j] << " ";exit(0);}
 for (int j=0;j<4;j++)
  if ((b[k]|j)==c[k] && (b[k]&j)==d[k]) {b[k+1]=j;rec(b,k+1);}
 return;
}

int main()
{
  //freopen("rvq.in","r",stdin);
  //freopen("rvq.out","w",stdout);
  ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  for (i=0;i<n-1;i++) cin >> c[i];
  for (i=0;i<n-1;i++) cin >> d[i];
  for (i=0;i<4;i++)
  {
   a[0]=i;
   rec(a,0);
  }
  cout << "NO";
  return 0;
}