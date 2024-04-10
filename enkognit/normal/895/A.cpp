#include <bits/stdc++.h>

using namespace std;

string s1,s2;
long long n,v,m,i,j,x,k,l=360,a[100001];
bool t[361];

int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("outout.txt","w",stdout);
  cin >> n;
  for (i=1;i<=n;i++)
  {
   cin >> a[i];
  }
  l=360;
  for (i=1;i<=n;i++)
  {
   k=0;
   for (j=0;j<n;j++)
   {
    m=i+j-n*(i+j>n);
    k+=a[m];
    if (abs(360-k*2)<l) l=abs(360-k*2);
   }
  }
  cout << l;
  return 0;
}