#include <bits/stdc++.h>

using namespace std;

const int maxint = 2*1e9;

bool t[1002][1002];
int a[1002],b[1002],o1[110000],o2[110000],o3[110000];
string s;
int h=0,g=0,l=0,q1,q2,n,m;
char c;

double sqr(int x)
{
 return x*x;
}

double rast(double x1,double y1,double x2,double y2)
{
 return sqrt(sqr(x1-x2)+sqr(y1-y2));
}

void add(int x,int y,int z)
{
 if ((x<1) || (y<1) || (x>h) || (y>g) || (t[x][y]==true)) return;
 if (z>l) l=z;
 q2++;
 o1[q2]=x;
 o2[q2]=y;
 o3[q2]=z;
}

int main()
{
  //freopen("shelf.in","r",stdin);
  //freopen("shelf.out","w",stdout);
    cin >> c >> n;
    if (c-96-1>0) m++;
    if (c-96+1<=8) m++;
    if (n-1>0) m++;
    if (n+1<=8) m++;
    if (c-96-1>0 && n-1>0) m++;
    if (c-96-1>0 && n+1<=8) m++;
    if (c-96+1<=8 && n-1>0) m++;
    if (c-96+1<=8 && n+1<=8) m++;
    cout << m << endl;
    return 0;
}