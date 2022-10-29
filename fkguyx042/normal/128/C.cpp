#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,n,m,k;
const int Mo=(int)1e9+7;
int power(int x,int y)
{
      int sum=1;
      for (;y;y>>=1)
      {
           if (y&1) sum=1ll*sum*x%Mo;
           x=1ll*x*x%Mo;
      }
      return sum;
}
int C(int x,int y)
{
       if (x<y) return 0;
       int sum=1,Su=1;
       for (i=1;i<=x;++i) sum=1ll*sum*i%Mo;
       Su=sum;
       sum=1;
       for (i=1;i<=y;++i) sum=1ll*sum*i%Mo;
       Su=1ll*Su*power(sum,Mo-2)%Mo;
       sum=1;
       for (i=1;i<=x-y;++i) sum=1ll*sum*i%Mo;
       Su=1ll*Su*power(sum,Mo-2)%Mo;
       return Su;
}
int main()
{
      scanf("%d%d%d",&n,&m,&k);
      printf("%d\n",1ll*C(n-1,2*k)*C(m-1,2*k)%Mo);
}