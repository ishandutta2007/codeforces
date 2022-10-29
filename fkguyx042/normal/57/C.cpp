#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=(int)1e9+7;
int i,j,m,n,p,k,Ans;
int A[1000001],B[1000001];
int C(int x,int y)
{ if (!y) return 1;
  int sum=A[x];
  sum=1ll*sum*B[y]%Mo;
  sum=1ll*sum*B[x-y]%Mo;
  return sum;
}
int pow(int x,int y)
{ int sum=1;
  for (;y;y>>=1)
  {  if (y&1) sum=1ll*sum*x%Mo;
     x=1ll*x*x%Mo;
}
return sum;
}
int main()
{
  scanf("%d",&n);
  A[1]=1;
  for (i=2;i<=n;i++) A[i]=1ll*A[i-1]*i%Mo;
  B[1]=1;
  B[0]=1;
  for (i=2;i<=n;i++) B[i]=1ll*B[i-1]*pow(i,Mo-2)%Mo;
  for (i=1;i<=n;i++){ (Ans+=1ll*C(n,i)*C(n-1,i-1)%Mo); 
                        if (Ans>=Mo) Ans-=Mo;
                    } 
  Ans=Ans*2-n;
  if (Ans<0) Ans+=Mo;
  if (Ans>=Mo) Ans-=Mo;
  printf("%d\n",Ans);
}