#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
   int n,k,a,i;
scanf("%d%d",&n,&k);
      int index=1;
      long long res=0;
       scanf("%d",&a);
      for(i=2;i<=n;++i)
      {
          scanf("%d",&a);
          if(res-(long long)index*(n-i)*a<k)
          printf("%d\n",i);
          else 
          {
              res+=(long long)index*a;
              index++;
          }
      }
   return 0;
}