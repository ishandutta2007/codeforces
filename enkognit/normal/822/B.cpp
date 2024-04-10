#include <iostream>
#include <cstring>
#include <cmath>
#include <stdlib.h>

using namespace std;

string s,s1;
bool t[301][301];
int n,m,k=0,q1,q2,x,y,l,i,j=0,a[5];

double sqr(double x)
{
 return x*x;
}

/*void add(int x,int y)
{
 if ((x<1)||(y<1)||(x>n)||(y>m)||(t[x][y]==true)) return;
 q2++;
 o1[q2]=x;
 o2[q2]=y;
 t[x][y]=true;
}*/

int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n >> m;
  k=10000;
  cin >> s;
  cin >> s1;
  for (i=0;i<m-n+1;i++)
  {
   l=0;
   for (j=0;j<n;j++)
   {
    l+=(s1[i+j]!=s[j]);
   }
   if (l<k) {k=l;x=i;}
  }
  cout << k << endl;
  for (i=x;i<x+n;i++)
  {
   if (s1[i]!=s[i-x]) cout << i-x+1 << " ";
  }
  return 0;
  //system("pause");
}