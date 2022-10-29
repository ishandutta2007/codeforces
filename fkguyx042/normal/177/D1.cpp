#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 100005

using namespace std;
int i,j,m,n,p,k,Mo,a[N],b[N];
int main()
{
	 scanf("%d%d%d",&n,&m,&Mo);
	 for (i=1;i<=n;++i) scanf("%d",&a[i]);
	 for (i=1;i<=m;++i) scanf("%d",&b[i]),b[i]=(b[i-1]+b[i])%Mo;
	 for (i=1;i<=n;++i)
	 {
	      int l=max(1,i-n+m),r=min(m,i);
	      printf("%d ",(a[i]+b[r]-b[l-1]+Mo)%Mo);
	}
}