#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define ep 1e-8
#define fr(a,b,c) for (a=b;a<=c;a++)
using namespace std;

int n,k;
double a[11111],l=11111,r=0,m,re;

int ok(double val)
{
    int i;
    double x=0,y=0;
    fr(i,1,n)
      if (a[i]>val) x+=a[i]-val;
      else y+=val-a[i];
    return (x-x*k/100-y>=0);
}

int main()
{
    int i;
    cin >> n >> k;
    fr(i,1,n) 
    {
       cin >> a[i];
       l=min(l,a[i]);
       r+=a[i];
    }
    r/=n;
    if (r==l) re=r;
    while (r-l>ep)
    {
       m=(l+r)/2;
       if (ok(m)) 
       {
           re=m; l=m;
       }   
       else r=m;
    }
    printf("%0.9lf\n",re);
    //system("pause");
    return 0;
}