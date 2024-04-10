#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A[200001],B[200001],w[200001],h[200001],i,j,m,n,p,k;
int main()
{ scanf("%d",&n);
 for (i=1;i<=n;i++) scanf("%d%d",&w[i],&h[i]),k+=w[i],A[i]=max(A[i-1],h[i]);
 for (i=n;i;i--) B[i]=max(B[i+1],h[i]);
 for (i=1;i<=n;i++) printf("%I64d ",1ll*(k-w[i])*max(A[i-1],B[i+1]));
}