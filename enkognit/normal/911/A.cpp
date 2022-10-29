#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll i,j,k,l,n,m,a[100001];

int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
  l=1000000000;
  m=1000001;
  for (i=1;i<=n;i++) {cin >> a[i];if (a[i]<l) {l=a[i];}}
  k=0;
  for (i=1;i<=n;i++)
   if (a[i]==l)
    if (k==0) k=i; else
    {m=min(m,abs(i-k));k=i;}
    cout << m;
  return 0;
}