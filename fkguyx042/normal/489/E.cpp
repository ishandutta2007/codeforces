#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int i,j,m,n,p,k,last[1001],x[1001],b[1001],Ans[1001],Q[1001],l;
double f[1001],ans[1001];
bool check(double y)
{   int i,j;
     for (i=1;i<=n;i++) f[i]=(int)1e9;
     f[0]=0;
     memset(last,0,sizeof(last));
       for (i=1;i<=n;i++)
         for (j=0;j<i;j++)
          if (f[i]>f[j]+sqrt(abs(x[i]-x[j]-l))-1.0*y*b[i])
          {   f[i]=f[j]+sqrt(abs(x[i]-x[j]-l))-1.0*y*b[i];
              last[i]=j;
          }
      if (f[n]<=0) return true;
       return false;
} 
int main()
{ scanf("%d%d",&n,&l);
 for (i=1;i<=n;i++) scanf("%d%d",&x[i],&b[i]);
 double l=0,r=1e5,mid=0;
 for (i=1;i<=100;i++)
{   mid=(l+r)/2.0;
  if (check(mid)) { memcpy(Ans,last,sizeof(Ans)); memcpy(ans,f,sizeof(ans)); r=mid; }
   else l=mid;
}
j=n;
for (;j;j=Ans[j]) Q[++Q[0]]=j;
for (i=Q[0];i;i--) printf("%d ",Q[i]);
printf("\n");
}