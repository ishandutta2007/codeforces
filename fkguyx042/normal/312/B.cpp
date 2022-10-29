#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b,c,d;
double t,t1;
int main()
{ scanf("%d%d%d%d",&a,&b,&c,&d);
  t=1.0*a/(1.0*b);
  t1=1.0*c/(1.0*d);
  printf("%.10lf\n",t/(t+t1-t*t1));
}