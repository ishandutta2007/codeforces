#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long x;
int sum[25],k;
int main()
{ scanf("%I64d%d",&x,&k);
  for (;x;x/=10ll)
  sum[++sum[0]]=x%10;
  for (int i=sum[0];i;i--)
  {   int X=i;
      for (int j=i-1;j;j--)
         if (sum[j]>sum[X]&&i-j<=k)  X=j;
      for (int j=X;j<i;j++)
        swap(sum[j],sum[j+1]);
        k-=(i-X);
}
for (int i=sum[0];i;i--) printf("%d",sum[i]);
}