#include <iostream>
#include <algorithm>
#include <cmath>
//#include <queue>
#include <cstdio>
#define ll long long
#define fi first
#define se second
#define pb push_back

using namespace std;

int i,r,n,m,j,l,a[10001];
double k,x[10001],y[10001],e;

double sqr(double h)
{
 return h*h;
}

int main()
{
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 //ios_base::sync_with_stdio(0);
 cin >> n >> m;
 for (i=1;i<=n;i++)
 {
  cin >> x[i] >> y[i] >> a[i];
 }
 for (i=1;i<n;i++)
  for (j=i+1;j<=n;j++)
   if (sqrt(sqr(x[i])+sqr(y[i]))>sqrt(sqr(x[j])+sqr(y[j])))
 {
  swap(x[i],x[j]);
  swap(y[i],y[j]);
  swap(a[i],a[j]);
 }
 cout.precision(7);
 for (i=1;i<=n;i++)
 {
  if (m<1000000) m+=a[i];
  if (m>=1000000) {cout << sqrt(sqr(x[i])+sqr(y[i])) << "\n";exit(0);}
 }
 cout << "-1";
 return 0;
}