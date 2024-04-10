#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
double sum,ans,a[4010];
int i,j,z,n;
double min(double a,double b){return (a>b)?b:a;}
int mi(int a,int b){return (a>b)?b:a;}
int main()
{
 scanf("%d",&n);
 for (i=1;i<=2*n;i++)
  scanf("%lf",&a[i]);
 
 for (i=1;i<=2*n;i++)
 for (i=1;i<=2*n;i++)
  if (int(a[i])==a[i])
   z++;else sum+=a[i]-1.0*int(a[i]);
  ans=1e11;
 for (i=max(0,n-z);i<=mi(2*n-z,n);i++)
  ans=min(ans,fabs(sum-i));
 printf("%.3lf\n",ans);
 return 0;
}