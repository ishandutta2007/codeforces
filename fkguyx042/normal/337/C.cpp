#include<cstdio>
#include<algorithm>
#include<cstring>
#define Mo 1000000009
using namespace std;
int i,j,m,n,p,k,Now,Tot,Ans;
int pow(int y)
{ int x=2,sum=1;
   for (;y;y>>=1)
   {   if (y&1) sum=1ll*sum*x%Mo;
       x=1ll*x*x%Mo; }
return sum;
}
int main()
{ scanf("%d%d%d",&n,&m,&k);
  Now=n-m;
  if (m-1ll*Now*(k-1)<k) 
   printf("%d\n",m);
   else { 
            Tot=(m-1ll*Now*(k-1))/k;
           Ans=pow(Tot+1);
           Ans-=2; if (Ans<0) Ans+=Mo;
           Ans=1ll*Ans*k%Mo;
           Ans=(Ans+(m-1ll*Tot*k))%Mo;
           printf("%d\n",Ans);
    }
}