#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
double a,b,c,s;
int main()
{  scanf("%lf%lf%lf%lf",&s,&a,&b,&c);
   if (a==0&&b==0&&c==0) printf("%.10lf %.10lf %.10lf\n",s,0,0);
   else printf("%.10lf %.10lf %.10lf\n",1.0*a*s/(a+b+c),1.0*b*s/(a+b+c),1.0*c*s/(a+b+c));
}