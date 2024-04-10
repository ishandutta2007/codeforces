#include <bits/stdc++.h>

using namespace std;

int i,j,u,k,l,n,m,x,y,a[1001][1001];
string s;

int main()
{
  //freopen(".in","r",stdin);
  //freopen(".out","w",stdout);
  k=0;
  for (i=1;i<=9;i++)
   for (j=1;j<=3;j++)
   {
    cin >> s;
    for (u=0;u<3;u++)
     if (s[u]=='x')a[i][(j-1)*3+u+1]=1;else
     if (s[u]=='o')a[i][(j-1)*3+u+1]=2;
   }
   cin >> x >> y;
   if (x%3==0) x=3; else x=x%3;
   if (y%3==0) y=3; else y=y%3;
   for (i=1;i<=3;i++)
    for (j=1;j<=3;j++)
     if (a[(x-1)*3+i][(y-1)*3+j]==0) {a[(x-1)*3+i][(y-1)*3+j]=3;k++;}
     if (k==0)
     for (i=1;i<=9;i++)
      for (j=1;j<=9;j++) if (a[i][j]==0) a[i][j]=3;
  for (i=1;i<=9;i++)
  {
   for (j=1;j<=9;j++)
   {
    if (a[i][j]==1) cout << "x"; else
    if (a[i][j]==2) cout << "o"; else
    if (a[i][j]==0) cout << "."; else
    if (a[i][j]==3) cout << "!";
    if (j%3==0) cout << " ";
   }
   if (i%3==0)cout << "\n" << "\n"; else cout << "\n";
  }
  return 0;
}