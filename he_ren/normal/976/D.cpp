#include<cstdio>
const int MAXN = 3e2 + 5;
const int MAXM = 1e6 + 5;
const int MAXD = 1e3 + 5;

int d[MAXN];
int g[MAXD][MAXD];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&d[i]);
	
	int tot=d[n]+1;
	for(int k=1; ; ++k)
	{
		int l=k, r=n-k+1;
		if(l>r) break;
		for(int i=d[l-1]+1; i<=d[l]; ++i)
			for(int j=d[l-1]+1; j<i; ++j)
				g[i][j]=g[j][i]=1;
		
		for(int i=d[l-1]+1; i<=d[l]; ++i)
			for(int j=d[l]+1; j<=d[r]+1; ++j)	
				g[i][j]=g[j][i]=1;
	}
	
	int m=0;
	for(int i=1; i<=tot; ++i)
		for(int j=1; j<i; ++j)
			if(g[i][j]) ++m;
	printf("%d\n",m);
	for(int i=1; i<=tot; ++i)
		for(int j=1; j<i; ++j)
			if(g[i][j]) printf("%d %d\n",i,j);
	return 0;
}