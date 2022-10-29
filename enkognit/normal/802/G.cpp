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
  cin >> s;
  for (i=0;i<s.length();i++)
  {
   if (s[i]=='h' && s1=="") s1+='h'; else
   if (s[i]=='e' && s1=="h") s1+='e'; else
   if (s[i]=='i' && s1=="he") s1+='i'; else
   if (s[i]=='d' && s1=="hei") s1+='d'; else
   if (s[i]=='i' && s1=="heid") s1+='i';
  }
  if (s1=="heidi") cout << "YES"; else cout << "NO";
  return 0;
  //system("pause");
}