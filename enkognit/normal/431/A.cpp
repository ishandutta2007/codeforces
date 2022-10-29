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
  for (i=1;i<=4;i++) cin >> a[i];
  cin >> s;
  for (i=0;i<s.length();i++) k+=a[s[i]-48];
  cout << k;
  return 0;
  //system("pause");
}