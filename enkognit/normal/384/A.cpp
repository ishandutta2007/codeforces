#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mx = 2*1e6;

bool t[101][101];
ll a[1001][1001],o1[100001],o2[100001];
int l,i,j,n,m,s1,s2,l1,l2,k;
string s;
char c,f;

double sqr(int x)
{
 return x*x;
}



double rast(double x1,double y1,double x2,double y2)
{
 return sqrt(sqr(x1-x2)+sqr(y1-y2));
}

int main()
{
    //freopen("shelf.in","r",stdin);
    //freopen("shelf.out","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    for (i=1;i<=n;i++)
     for (j=1;j<=n;j++)
      if (a[i+1][j]==0 && a[i-1][j]==0 && a[i][j+1]==0 && a[i][j-1]==0)
      {a[i][j]=1;k++;}
    cout << k << endl;
    for (i=1;i<=n;i++)
    {
     for (j=1;j<=n;j++)
      if (a[i][j]==1) cout << "C"; else cout << ".";
     cout << endl;
    }
    return 0;
 }



 /* cin >> c >> m;
    n=c-96;
 if (n+m<9)
    {
     if (n>m)
     {
      s1=8;
      s2=8-m+1;
     } else
     if (n<m)
     {
      s1=8-n+1;
      s2=8;
     } else
     if (n==m) {s1=8;s2=8;}
    }  else
    if (n+m>9)
    {
     if (n>m)
     {
      s2=1;
      s1=8-m+1;
     } else
     if (n<m)
     {
      s2=8-n+1;
      s1=1;
     } else
     if (n==m) {s1=1;s2=1;}
    } else
    if (n+m==9)
    {
     if (n>m) {s1=1;s2=8;} else {s1=8;s2=1;}
    }
    if (n+4<=8 && n+4!=s1) {l1=n+4;l2=m;} else
    if (n-4>1 && n-4!=s1) {l1=n-4;l2=m;} else
    if (m+4<=8 && m+4!=s2) {l1=n;l2=m+4;} else
    if (m-4<=8 && m-4!=s2) {l1=n;l2=m-4;} else
    if (n+3<=8 && n+3!=s1) {l1=n+3;l2=m;} else
    if (n-3>1 && n-3!=s1) {l1=n-3;l2=m;} else
    if (m+3<=8 && m+3!=s2) {l1=n;l2=m+3;} else
    if (m-3<=8 && m-3!=s2) {l1=n;l2=m-3;}
    cout << (char)(l1+96) << l2 << endl;
    cout << (char)(s1+96) << s2 << endl;*/