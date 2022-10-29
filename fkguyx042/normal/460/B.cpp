#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,a,b,c,Ans[100001];
long long x;
int digit(long long x)
{ int sum=0;
    for (;x;x/=10) sum+=x%10;
    return sum;
}
long long pow(int x,int y)
{ long long Rp=1,i;
  for (i=1;i<=y;i++) Rp*=x;
  return Rp;
}
int main()
{  scanf("%d%d%d",&a,&b,&c);
   for (i=0;i<=100;i++)
 {  long long sum=1ll*b*pow(i,a)+c;
   if (sum>0&&sum<(int)1e9&&digit(sum)==i) Ans[++Ans[0]]=sum;
 }
 printf("%d\n",Ans[0]);
 for (i=1;i<=Ans[0];i++) printf("%d ",Ans[i]);
}