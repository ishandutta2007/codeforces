#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,s,k;
long long f[101],Ans[101];
int main()
{ scanf("%d%d",&s,&k);
  f[1]=1;
  for (i=2;f[i-1]<=s;i++)
  {   
     for (j=i-1;j>=max(1,i-k);j--)
       f[i]+=f[j];  
  }
  i-=2;
  for (j=i;j&&s;j--)
   if (s>=f[j])
     s-=f[j],Ans[++Ans[0]]=f[j];
  if (Ans[0]==1) Ans[0]++;
  printf("%I64d\n",Ans[0]);
  for (i=1;i<=Ans[0];i++)
  printf("%I64d ",Ans[i]);
}