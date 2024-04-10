#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pu push
#define sqr(a) ((a)*(a))

using namespace std;

ll n,m=-1e12,i,j,k,l;
bool t[1001];
ll a[1001];

int main()
{
  //ios_base::sync_with_stdio(0);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  n=14;
  for (i=1;i<=n;i++) cin >> a[i];
  for (i=1;i<=n;i++)
   if (a[i]>0)
  {
   ll z=a[i]/14;
   k=0;
   ll r=a[i];
   a[i]=0;
   for (int j=1;j<=n;j++)
   {
    bool tt=0;
    if ((j>i && j-i<=r%14)||(j<i && 14-i+j<=r%14))tt=1;
    if ((a[j]+z+tt)%2==0)k+=a[j]+z+tt;
   }
   a[i]=r;
   if (k>m) m=k;
  }
  if (m==-1e12) cout << 0;else cout << m;
  return 0;
}