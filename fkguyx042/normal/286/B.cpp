#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 3000005

using namespace std;
int i,j,m,n,p,k,start,end;
int Q[N],a[N];
int main()
{
	 scanf("%d",&n); start=1; end=n;
	 for (i=1;i<=n;++i) a[i]=i;
	 for (i=2;i<=n;++i)
	 {
	 	  Q[0]=0;
	 	  for (j=start;j<=end;)
	 	  {  
	 	    Q[++Q[0]]=j;
	 	    j=min(end+1,j+i);
	 	  }
	 	  Q[++Q[0]]=end+1;
	 	  for (j=Q[0];j>1;--j) swap(a[Q[j]],a[Q[j-1]]);
	 	  start++; end++;
	 }
	 for (i=start;i<=end;++i) printf("%d ",a[i]);
}