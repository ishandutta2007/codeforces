#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=(int)1e9+7;
int i,j,m,n,p,k,t;
long long f[1001][46],Ans[1001][46],A[1001][46],JC[51];
void Do()
{  f[0][0]=1;
   int i,j,k;
     for (i=1;i<=1000;i++)
       for (j=1000;j>=i;j--)
          for (k=45;k;k--)
            (f[j][k]+=f[j-i][k-1])%=Mo;
    for (i=0;i<=1000;i++) A[i][1]=1;
     for (int h=2;h<=45;h++) 
        for (int q=0;q<=1000;q++)  for (j=0;j<=q;j++) (A[q][h]+=A[q-j][h-1])%=Mo;
JC[1]=1; for (i=2;i<45;i++) JC[i]=1ll*JC[i-1]*i%Mo;
    for (i=1;i<=1000;i++)
      for (j=1;j<=45;j++)
      {    if (i==3)
	         i=3; 
        for (k=1;i-k>=0;k++)
          Ans[i][j]=(Ans[i][j]+1ll*f[k][j]*A[i-k][j+1]%Mo)%Mo;
        Ans[i][j]=1ll*Ans[i][j]*JC[j]%Mo;
    }
}
int main()
{ scanf("%d",&t); Do();
for (;t--;)
{ scanf("%d%d",&n,&k);
   if (k>45) printf("0\n");
   else printf("%I64d\n",Ans[n][k]);
}
}