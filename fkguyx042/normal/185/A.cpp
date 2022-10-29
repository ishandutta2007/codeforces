#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=(int)1e9+7;
int i,j,m,p,k;
long long n;
int A[3][3],B[3];
void cheng()
{ int C[3]={0},i,j,k;
  for (k=1;k<=2;k++)
    for (j=1;j<=2;j++)
      (C[j]+=1ll*B[k]*A[k][j]%Mo)%=Mo;
    memcpy(B,C,sizeof(C));
}
void Cheng()
{  int C[3][3]={0},i,j,k;
  for (k=1;k<=2;k++)
    for (i=1;i<=2;i++)
      for (j=1;j<=2;j++)
       (C[i][j]+=1ll*A[i][k]*A[k][j]%Mo)%=Mo;
       memcpy(A,C,sizeof(A));
  }
void Go(long long n)
{  for (;n;n>>=1ll)
{   if (n&1ll) cheng();
    Cheng();
}
}
int main()
{ scanf("%I64d",&n);
  B[1]=1;
  A[1][1]=3;
  A[2][1]=1;
  A[1][2]=1;
  A[2][2]=3;
  Go(n);
  printf("%d\n",B[1]);
}