#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 1000005

using namespace std;
int i,j,m,n,p,k,A[N],B[N],flag;
long long a[N],b[N];
int main()
{
	  scanf("%d",&n);
	  for (i=1;i<=n;++i) scanf("%d",&a[i]);
	  for (i=1;i<=n;++i) scanf("%d",&b[i]);
	  for (i=2;i<=n;++i) a[i]+=a[i-1],b[i]+=b[i-1];
	  if (a[n]>b[n]) swap(a,b),flag=1;
	  memset(A,-1,sizeof(A));
	  for (i=0;i<=n;++i)
	  {
	  	   int id=lower_bound(b,b+n+1,a[i])-b;
	  	   int x=b[id]-a[i];
	  	   if (A[x]!=-1) 
		   {
	  	   	 if (!flag) { 
	  	   	        printf("%d\n",i-A[x]);
				    for (j=A[x]+1;j<=i;++j) printf("%d ",j);
				    puts("");
				    printf("%d\n",id-B[x]);
				    for (j=B[x]+1;j<=id;++j) printf("%d ",j);
				}
				else 
				{
					printf("%d\n",id-B[x]);
				    for (j=B[x]+1;j<=id;++j) printf("%d ",j); 
				    puts("");
	  	   	        printf("%d\n",i-A[x]);
				    for (j=A[x]+1;j<=i;++j) printf("%d ",j);
				}
	  	   	 break; 
		   }
		   else A[x]=i,B[x]=id;
	  }
}