#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A[505],n,m,ans,i,j;
char c[105][105];
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;++i) scanf("%s",&c[i]);
	for (i=1;i<n;++i)
	  for (j=0;j<m-1;++j)
	  {
	  	  memset(A,0,sizeof(A));
	  	  A[c[i][j]]++;
	  	  A[c[i][j+1]]++;
	  	  A[c[i+1][j]]++;
	  	  A[c[i+1][j+1]]++;
	  	  if (A['f']==1&&A['a']==1&&A['c']==1&&A['e']==1) ans++;
	  }
	printf("%d\n",ans);
}