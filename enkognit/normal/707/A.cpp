#include <bits/stdc++.h>

using namespace std;

const int maxint = 2*1e9;

bool t[5002];
long long a[11000];
string s;
int h=0,l=0,q1,q2,n,k,g,y,m=0;
char c;

double sqr(int x)
{
 return x*x;
}

double rast(double x1,double y1,double x2,double y2)
{
 return sqrt(sqr(x1-x2)+sqr(y1-y2));
}

void rec(long long k,int g,bool *t)
{
 if (k==m) {l++;return;}
 for (int i=g;i<=n;i++)
  if ((t[i]==false) && (k+a[i]<=m))
 {
  t[i]=true;
  rec(k+a[i],i,t);
  t[i]=false;
 }
}

int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
    cin >> n >> k;
    for (int i=1;i<=n;i++)
     for (int j=1;j<=k;j++)
     {
      cin >> c;
      if (c=='C') g++;
      if (c=='M') m++;
      if (c=='Y') y++;
     }
     if ((g==0) && (y==0) && (m==0)) cout << "#Black&White"; else cout << "#Color";
    return 0;
}