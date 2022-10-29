#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <cstdio>
using namespace std;
int main()
{
 int n,m,k=0,i,j;
 cin >> n;
 cin >> m;
 int a[3001],b[3001];
 short c[3001],d[3001];
 for (i=0; i < n+m; i++) {d[i]=0;c[i]=0;}
 for (i=0; i < n; i++) {cin >> a[i];}
 for (i=0; i < m; i++)
 {
  cin >> b[i];
 }
 for (i=0; i < n; i++)
 {
  for (j=0; j < m; j++)
  {if ((b[j]==a[i]) && (d[j]==0) && (c[i]==0)) {k++;d[j]=1;c[i]=1;break;continue;} else k+=0;}
  for (j=0; j < m; j++)
  {if ((d[j]==0) && (b[j]>a[i]) && (c[i]==0)) {k++;d[j]=1;c[i]=1;b[j]=a[i];}}
 }
 if (n-k<0) cout << 0; else cout << n-k;
 return 0;
}