#include<cstdio>
#include<algorithm>
#include<cstring>
const int Mo=(int)1e9+7;
using namespace std;
int a[2][54],i,j,m,p,k,ans,X,x[54][54];
long long n;
char c[2];
int f[54][54];
void cheng()
{   int c[2][54]={0},i,j,k;
    for (k=0;k<=m;k++)
      for (i=0;i<=m;i++)
        (c[1][i]+=1ll*a[1][k]*x[k][i]%Mo)%=Mo;
    for (i=0;i<=m;i++) a[1][i]=c[1][i];
}
void Cheng()
{  int c[54][54]={0},i,j,k;
   for (k=0;k<=m;k++)
     for (i=0;i<=m;i++) 
       for (j=0;j<=m;j++)
         (c[i][j]+=1ll*x[i][k]*x[k][j]%Mo)%=Mo;
    memcpy(x,c,sizeof(x));
}
void power()
{  for (;n;n>>=1ll)
   {    if (n&1ll) cheng();
        Cheng();
}
}
int main()
{ scanf("%I64d%d%d",&n,&m,&k);m--;n--;
 for (;k--;)
 { scanf("%s",&c);
   if (c[0]<='Z') p=c[0]-'A'+26; else p=c[0]-'a';
   if (c[1]<='Z') X=c[1]-'A'+26; else X=c[1]-'a';
   f[p][X]=1;
 }
 for (i=0;i<=m;i++)
   for (j=0;j<=m;j++)
      if (!f[i][j]) x[i][j]=1;
 for (i=0;i<=m;i++) a[1][i]=1;
 power();
 for (i=0;i<=m;i++) (ans+=a[1][i])%=Mo;
 printf("%d\n",ans);
}