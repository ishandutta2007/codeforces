#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
double a,b,c;
char s[12][100]={"x^y^z","x^z^y","(x^y)^z","(x^z)^y","y^x^z","y^z^x","(y^x)^z","(y^z)^x","z^x^y",
"z^y^x","(z^x)^y","(z^y)^x"};
struct num
{
	int a,p;
	double x;
	bool operator>(num y)
	{
		return a>y.a || a==y.a && x>y.x+1e-12;
	}
}x,y={};
inline void orz(double a,double b,double c,int p)
{
	x.p=p;
	if(fabs(a-1)<1e-12)
	  {
	   x.a=2;
	   x.x=0;
      }
    else
      if(a<1)
        {
         x.a=1;
         x.x=-log(-log(a))-log(b)*c;
        }
      else
        {
         x.a=3;
         x.x=log(log(a))+log(b)*c;
        }
    if(x>y)
      y=x;
}
inline void orz_(double a,double b,double c,int p)
{
	x.p=p;
	if(fabs(a-1)<1e-12)
	  {
	   x.a=2;
	   x.x=0;
      }
    else
      if(a<1)
        {
         x.a=1;
         x.x=-log(-log(a))-log(b*c);
        }
      else
        {
         x.a=3;
         x.x=log(log(a))+log(b*c);
        }
    if(x>y)
      y=x;
}
int main()
{
	scanf("%lf%lf%lf",&a,&b,&c);
	orz(a,b,c,0);
	orz(a,c,b,1);
	orz_(a,b,c,2);
	orz_(a,c,b,3);
	orz(b,a,c,4);
	orz(b,c,a,5);
	orz_(b,a,c,6);
	orz_(b,c,a,7);
	orz(c,a,b,8);
	orz(c,b,a,9);
	orz_(c,a,b,10);
	orz_(c,b,a,11);
	printf("%s\n",s[y.p]);
	return 0;
}