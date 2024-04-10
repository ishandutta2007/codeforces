#include<cstdio>
#include<cstdlib>
const int MAXN = 1e3 + 5;

inline void swap(int &a,int &b){ int t=a; a=b; b=t;}
inline void NO(void){ printf("NO"); exit(0);}

int g[MAXN][MAXN];

int main(void)
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	if(a>1 && b>1) NO();
	if(n==2 && a==1 && b==1) NO();
	if(n==3 && a==1 && b==1) NO();
	printf("YES\n");
	
	bool flag=0;
	if(b>1) swap(a,b), flag=1;
	for(int i=1; i<=n-a; ++i) g[i][i+1]=g[i+1][i]=1;
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			if(flag) g[i][j]^=1;
			if(i==j) g[i][j]=0;
			putchar(g[i][j]+'0');
		}
		putchar('\n');
	}
	return 0;
}