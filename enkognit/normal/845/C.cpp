#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

#define ll long long
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define fi first
#define se second

using namespace std;

ll n,m,i,j,k,l=0,r=0;
pll a[200001];

int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 cin >> n;
 for (i=1;i<=n;i++)
 {
  cin >> a[i].fi >> a[i].se;
 }
 sort(a+1,a+n+1);
 l=1;
 for (i=2;i<=n;i++)
 {
  if (a[i].fi>a[l].se) l=i; else
  if (r==0) r=i; else
  if (a[i].fi>a[r].se) r=i; else {cout << "NO\n";exit(0);}
 }
 cout << "YES\n";
 return 0;
}