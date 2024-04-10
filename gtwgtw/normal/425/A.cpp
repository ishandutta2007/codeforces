#include<stdio.h>
#include<algorithm>
using namespace std;
long a[205];long n,k;
long t1[205];
long t2[205];
long sum[205];
bool cmp1(long a,long b){return a<b;}
bool cmp2(long a,long b){return a>b;}
int main()
{
    scanf("%ld%ld",&n,&k);
    for(long i=1;i<=n;i++){scanf("%ld",&a[i]);sum[i]=sum[i-1]+a[i];}
    long ans=-2100000000;
    for(long i=1;i<=n;i++)
    for(long j=i;j<=n;j++)
    {
             t1[0]=t2[0]=0;long reu=sum[j]-sum[i-1];
             for(long s=i;s<=j;s++)t1[++t1[0]]=a[s];
             for(long s=1;s<i;s++)t2[++t2[0]]=a[s];
             for(long s=j+1;s<=n;s++)t2[++t2[0]]=a[s];
             sort(t1+1,t1+1+t1[0],cmp1);
             sort(t2+1,t2+1+t2[0],cmp2);
             for(long i=1;i<=k;i++)
             if((i>t1[0])||(i>t2[0]))break;
             else
             {
                 if(-t1[i]+t2[i]>=0)
                 {
                                   reu+=-t1[i]+t2[i];
                                   }
                 else break;
                 }
             if(reu>ans)ans=reu;
             }
    printf("%ld\n",ans);
    return 0;
}