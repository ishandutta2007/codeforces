#include <bits/stdc++.h>

#define fr front
#define fi first
#define se second
#define pb push_back
#define ll long long
#define pu push
#define mp make_pair
#define pll pair<ll,ll>

using namespace std;

ll n,m,k,l,i,a[200001];

int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  //ios_base::sync_with_stdio(0);
  cin >> n >> m;k=n;
  for (i=1;i<=n;i++) cin >> a[i];
  sort(a+1,a+n+1);
  //for (i=1;i<=n;i++) cout << a[i] << " ";
  i=1;
  while (i<n)
  {
   ll y=1;
   while (a[i]==a[i+1]){i++;y++;}
   if (a[i+1]>a[i] && a[i]+m>=a[i+1]) k-=y;
   i++;
  }
  cout << k;
  return 0;
}