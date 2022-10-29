#include <bits/stdc++.h>

using namespace std;

const int maxint = 2*1e9;

bool t[5002];
long long a[11000];
string s;
int h1,h2,l1,l2,h3,h4,l3,l4,q1,q2,n,m,k;
char c,h,g,f,d;

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
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
    cin >> h >> g >> c >> f >> d;
    h1=h-48;
    h2=g-48;
    l1=f-48;
    l2=d-48;
    cin >> h >> g >> c >> f >> d;
    h3=h-48;
    h4=g-48;
    l3=f-48;
    l4=d-48;
    if (h1*10+h2>=h3*10+h4) k=h1*10+h2-h3*10-h4; else
    k=24-(h3*10+h4-h1*10-h2);
    if (l1*10+l2>=l3*10+l4) m=l1*10+l2-l3*10-l4; else
    {m=60-(l3*10+l4-l1*10-l2);if (k-1<0)k+=24;k--;}
    cout << k/10 << k%10 << ":" << m/10 << m%10 << endl;
    return 0;
}