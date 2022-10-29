#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#define len length()

using namespace std;

int l,n,u,m,i,j,a[100001];
string s,s1;
bool t[10001][10001];

long double sqr(long double h)
{
 return h*h;
}

int main()
{
   //freopen("mirror.in","r",stdin);
   //freopen("mirror.out","w",stdout);
   cin >> n >> m;
   bool t=0;
   for (i=1;i<=n;i++)
   {
    cin >> a[i];
   }
   l=100000;
   sort(a+1,a+n+1);
   for (i=1;i<n;i++)
    for (j=i+1;j<=n;j++)
    if (a[j]-a[i]<=m) {t=1;l=min(l,i-1+n-j);}
if (t==0) cout << n-1; else cout << l;
   return 0;
}