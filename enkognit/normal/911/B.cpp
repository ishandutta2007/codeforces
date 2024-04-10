#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll i,j,k,l,n,m,a[100001];

int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m >> k;
  for (i=1;i<n;i++)
  {
   l=max(l,min(m/i,k/(n-i)));
  }
  cout << l;
  return 0;
}