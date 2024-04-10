#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
double ans;
double power(double x,int y)
{double sum=1.0;
   for (;y;y>>=1)
   {  if (y&1) sum*=x;
      x=x*x; }
return sum;
}
int main()
{scanf("%d%d",&m,&n); 
  ans=m;
  for (i=1;i<m;i++)
    ans-=power((double)i/m,n);
    printf("%.12lf\n",ans);
}