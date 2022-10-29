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
  cin >> n;
  cin >> s;
  for (i=0;i<n;i++)
  {
   l+=(s[i]=='x');
   k+=(s[i]=='X');
  }
  cout << abs(k-l)/2 << endl;
  for (i=0;i<s.length();i++)
  {
   if (k==l) break;
   if (k>l)
   {
    if (s[i]=='X') {k--;l++;s[i]='x';}
   } else
   if (k<l)
   {
    if (s[i]=='x') {k++;l--;s[i]='X';}
   }
  }
  cout << s;
  return 0;
  //system("pause");
}