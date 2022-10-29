#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define len length()
#define fi first
#define se second
#define fr front()

using namespace std;

ll n,x,y,l,k,z,i,j,m;
bool t[100001];
ll a[101],b[101];

int main()
{
 //freopen("weights.in","r",stdin);
 //freopen("weights.out","w",stdout);
 cin >> m >> n;
 for (i=0;i<n;i++) cin >> a[i];
 sort(a,a+n);
 z=0;b[z]=1;
 for (i=1;i<n;i++)
 {
  if (a[i]==a[i-1]) b[z]++; else z++,b[z]++;
 }
 sort(b,b+z);
 reverse(b,b+z);
 for (i=100;i>0;i--)
 {
  ll u=m;
  for (j=0;j<=z;j++)
  {
   u-=b[j]/i;
   if (u<=0) {cout << i;exit(0);}
  }
 }
 cout << 0;
 return 0;
}