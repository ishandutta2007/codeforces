#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXN = 1e5 + 5;
using namespace std;

char a[MAXN],b[MAXN];
int f[MAXN],g[MAXN];

int main(void)
{
	scanf("%s%s",a+1,b+1);
	int n=strlen(a+1),m=strlen(b+1);
	
	for(int i=1,j=1; i<=m; ++i)
	{
		while(j<=n && a[j]!=b[i]) ++j;
		f[i]=j;
		if(j<=n) ++j;
	}
	g[m+1]=n+1;
	for(int i=m,j=n; i>=1; --i)
	{
		while(j>=1 && a[j]!=b[i]) --j;
		g[i]=j;
		if(j>=1) --j;
	}
	//for(int i=0; i<=m+1; ++i) printf("f[%d]: %d \t g[%d]: %d\n",i,f[i],i,g[i]);
	
	int l=1,r=m;
	for(int j=0; j<=m; ++j)
	{
		int i=lower_bound(f,f+m+1, g[j+1])-f;
		if(i)
		{
			if(r-l>j-i) l=i, r=j;
		}
		//printf("%d %d\n",i,j);
	}
	
	if(l==1 && r==m) putchar('-');
	else
	{
		for(int i=1; i<=m; ++i)
			if(i<l || i>r) putchar(b[i]);
	}
	return 0;
}