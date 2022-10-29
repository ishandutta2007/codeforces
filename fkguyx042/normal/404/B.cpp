#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int y,Now;
double a,d,x;
int main()
{ scanf("%lf%lf",&a,&d);
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {  x=i*d;
      long long cs=(long long)(x/a);
      double last=x-cs*a;cs%=4;
      if (!cs) printf("%.8lf %.8lf\n",last,0.);
      if (cs==1) printf("%.8lf %.8lf\n",a,last);
      if (cs==2) printf("%.8lf %.8lf\n",a-last,a);
      if (cs==3) printf("%.8lf %.8lf\n",0.,a-last);
}
}