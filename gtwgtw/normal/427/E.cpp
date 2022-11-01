
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[1000001];
long long b[1000001];
long long x[1000001];
long long i,j,m,n,p,k,ans,sum,sum1;
int main()
 { scanf("%I64d%I64d",&n,&m);
   for (i=1;i<=n;i++)
    scanf("%I64d",&x[i]);
    sort(x+1,x+1+n);
    a[1]=0;
    sum=0;
    sum1=0;
    for (i=2;i<=n;i++)
    { if ((i-2)%m==0)
       { sum+=x[i-1];
         sum1++;
         }
       a[i]=(x[i]*sum1-sum)*2;
}
b[n]=0;
sum=0;
sum1=0;
for (i=n-1;i>=1;i--)
    { if ((n-i-1)%m==0)
       { sum+=x[i+1];
         sum1++;
         }
       b[i]=(sum-x[i]*sum1)*2;
}
ans=a[1]+b[1];
for (i=1;i<=n;i++)
ans=min(ans,a[i]+b[i]);
printf("%I64d\n",ans);
return 0;
}