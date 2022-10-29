#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,A[305],B[305];
void get(int x,int *A)
{
	  if (x==1) A[1]=1;
	  else if (x==2) A[1]=3,A[2]=4;
	  else if ((x&1)==0)
	  {
	  	  for (i=1;i<x;++i) A[i]=1; A[x]=(x-2)/2;
	  }
	  else 
	  {
	  	  A[1]=2; for (i=2;i<x;++i) A[i]=1; A[x]=(x+1)/2;
	  }
}
int main()
{
	  scanf("%d%d",&n,&m);
	  get(n,A);
	  get(m,B);
	  for (i=1;i<=n;++i)
	  {
	  	  for (j=1;j<=m;++j) printf("%d ",A[i]*B[j]);
	  	  puts("");
	  }
}