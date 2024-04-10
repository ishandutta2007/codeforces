#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
long long t,n,ans;
int i,j,m,p,k,Case,Now;
int Two[101];
long long F[101][101],G[101][101];
void Do(long long x)
{ int sum=0;for (;x;x/=2ll)
  {   Two[++sum]=x&1ll; }
}
int main()
{  scanf("%I64d%I64d",&n,&t);
   for (;t%2==0;)
   {  Case++;
      t/=2;
   }
   if (t>1) printf("0\n");
else {   n++;
        Case++;
         F[1][1]=G[1][0]=1;
         if (Case==1) ans--;
         int Max=(int)log2(n)+1;
         for (i=1;i<=Max;i++)
         {
           for (j=0;j<=Case;j++)
         {    if (j>0) F[i][j]+=F[i-1][j-1]+G[i-1][j-1];
              G[i][j]+=G[i-1][j]+F[i-1][j];
         }
         if (i<Max) ans+=F[i][Case];
         }
         Now=0;
         Do(n);
         for (i=Max;i;i--)
           if (Now<=Case)
           if (i==1)
         {    if (Two[i]==0)
               ans+=G[i][Case-Now];
              else ans+=G[i][Case-Now]+F[i][Case-Now];
         }
         else {   if (Two[i]==1)
                    {  if (i!=Max)
                    ans+=G[i][Case-Now];Now++;
                    }
                    }
printf("%I64d\n",ans);
}
}