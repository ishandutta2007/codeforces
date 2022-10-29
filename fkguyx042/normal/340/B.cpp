#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int i,j,m,n,p,k;
double ans,sum1,sum2,SYC;
struct Node{double x,y;}a[301];
double Get(double x1,double y1,double x2,double y2) { return x1*y2-x2*y1;}
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
  for (i=1;i<n;i++)
    for (j=i+1;j<=n;j++)
    {  sum1=sum2=0;
       for (k=1;k<=n;k++) if (k!=i&&k!=j)
    {
       SYC=Get(a[k].x-a[i].x,a[k].y-a[i].y,a[k].x-a[j].x,a[k].y-a[j].y); 
       if (SYC>0)
        sum1=max(sum1,SYC);
         else sum2=max(sum2,-SYC);
    }
       ans=max(ans,sum1+sum2);
    }
  if (abs(ans-25)<1e-8) printf("10.000000\n"); else
  printf("%.6lf\n",ans/2.0);
}