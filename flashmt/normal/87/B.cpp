#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

int n,num,err[1010];
string a[1010],b[1010];

int find(string A)
{
  int i;
  fr(i,1,num)
     if (a[i]==A) return i;
  return 0;
}

void edit(string &B)
{
  int i,x=0,y=0,z;
  while (B[0]=='&') x++, B.erase(0,1);
  while (B[B.size()-1]=='*') y++, B.erase(B.size()-1,1);
  z=min(x,y);
  x-=z; y-=z;
  fr(i,1,x) B="&"+B;
  fr(i,1,y) B=B+"*";
}

int main()
{
  //freopen("b.in.3","r",stdin);
  int i;
  string type,A,B;
  cin >> n;
  a[++num]="void";
  b[num]="void";
  a[++num]="errtype";
  b[num]="errtype";
  err[num]=1;
  while (n--)
  {
    int x=0,y=0,z,bb,aa,xx,yy;
    cin >> type;
    if (type=="typedef")
    {
      cin >> A >> B;
      while (A[0]=='&') x++, A.erase(0,1);
      while (A[A.size()-1]=='*') y++, A.erase(A.size()-1,1);
      z=min(x,y);
      xx=x-z; yy=y-z;
      bb=find(B);
      if (!bb)
      {
        a[++num]=B;
        bb=num;
      }
      aa=find(A);
      if (!aa || err[aa]) err[bb]=1;
      else
      {
        B=b[aa];
        fr(i,1,xx) B="&"+B;
        fr(i,1,yy) B=B+"*";
        edit(B);
        err[bb]=(B[0]=='&');
        b[bb]=B;
      }
    }
    else
    {
      cin >> A;
      while (A[0]=='&') x++, A.erase(0,1);
      while (A[A.size()-1]=='*') y++, A.erase(A.size()-1,1);
      z=min(x,y);
      aa=find(A);
      if (!aa || err[aa]) cout << "errtype" << endl;
      else
      {
        A=b[aa];
        fr(i,1,x-z) A="&"+A;
        fr(i,1,y-z) A=A+"*";
        edit(A);
        if (A[0]=='&') cout << "errtype" << endl;
        else cout << A << endl;
      }
   }
 }
 return 0;
}