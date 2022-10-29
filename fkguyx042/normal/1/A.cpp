#include<cstdio>
using namespace std;
int i,j,m,n,p,k;
int main()
{
      scanf("%d%d%d",&n,&m,&k);
      printf("%I64d\n",1ll*((n/k)+(n%k!=0))*((m/k)+(m%k!=0)));
    //  for (;;);
}