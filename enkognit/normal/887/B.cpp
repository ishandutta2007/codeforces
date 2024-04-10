#include <bits/stdc++.h>

using namespace std;

int k,a[10][10],b[4],r,i,v,n,m;
char c;
bool t[10][10];
string s;

void rec(int k)
{
 int col=0,l=k+1;
 while (l>0)
 {
  col++;
  l/=10;
 }
 int d=0;
 int b[4]={};
 for (int i=1;i<=col;i++)
 {
  int h=10*(i-1);
  if (h==0) h=1;
  for (int j=1;j<=n;j++)
  {
   if (b[j]==1) continue;
   if (t[j][((k+1)/h)%10]==true && b[j]==0) {d++;b[j]=1;break;}
  }
 }
 if (d==col) rec(k+1); else
 {int d=0;
 int b[4]={};
 for (int i=1;i<=col;i++)
 {
  int h=10*(i-1);
  if (h==0) h=1;
  for (int j=n;j>=1;j--)
  {
   if (b[j]==1) continue;
   if (t[j][((k+1)/h)%10]==true && b[j]==0) {d++;b[j]=1;break;}
  }
 }if (d==col) rec(k+1);else {cout << k;exit(0);}}
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    m=6;
    for (int i=1;i<=n;i++)
     for (int j=1;j<=m;j++)
    {
     cin >> a[i][j];
     t[i][a[i][j]]=true;
    }
    rec(0);
    return 0;
}