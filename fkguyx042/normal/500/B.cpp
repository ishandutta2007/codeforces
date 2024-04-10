#include<cstdio>
#include<algorithm>
using namespace std;
int A[305][305],i,j,m,n,p,k,a[305];
char c[305];
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (i=1;i<=n;i++)
  { scanf("%s",&c);
    for (j=0;j<n;j++) A[i][j+1]=c[j]-'0';
  }
  for (k=1;k<=n;k++)
    for (i=1;i<=n;i++)
       for (j=1;j<=n;j++)
         if(A[i][k]&&A[k][j])
           A[i][j]=1;
  for (i=1;i<=n;i++)
{ k=i;  
     for (j=i+1;j<=n;j++)
     if (A[i][j]&&a[j]<a[k]) k=j;
     swap(a[i],a[k]);
}
for (i=1;i<=n;i++) printf("%d ",a[i]);
}