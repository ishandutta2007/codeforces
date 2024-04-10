#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int x,y,i,j,m,n,p,k,ans;
int A[5001],B[5001];
char c[5001][5001];
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)scanf("%s",&c[i]);
  for (i=0;i<m;i++)
  {  
      for (j=1;j<=n;j++)
        if (c[j][i]=='0') A[j]=0; else A[j]++;
        B[0]=0;
      for (j=1;j<=n;j++)
        if (A[j]>0) B[++B[0]]=A[j];
     sort(B+1,B+B[0]+1);
     for (j=1;j<=B[0];j++)
      ans=max(ans,B[j]*(B[0]-j+1));
 }
 printf("%d\n",ans);
}