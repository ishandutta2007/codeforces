#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int x[4001],sum[4001];
int A[50001],i,j,p,k,a,Case;
char c[4001];
long long ans;
int main()
{ scanf("%d",&a);
  scanf("%s",&c);
  int len=strlen(c);
  for (i=1;i<=len;i++) sum[i]=sum[i-1]+c[i-1]-'0';
  for (j=1;j<=len;j++)
   for (k=0;k<j;k++)
     A[sum[j]-sum[k]]++,Case++;
   for (i=1;i<=len;i++)
     for (j=0;j<i;j++)
     { int Sum=sum[i]-sum[j];
       if (Sum==0)
        { if (a==0) ans+=Case; }
       else  if (a%Sum==0)
       {   if (a/Sum<=40000)
            ans+=A[a/Sum];
       }
     }
  printf("%I64d\n",ans);
}