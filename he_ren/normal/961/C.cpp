#include<cstdio>
const int MAXN = 1e2 + 5;
const int inf = 0x3f3f3f3f;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

int n;
char a[5][MAXN][MAXN];
int c[5][2];

void calc(int k,int clr)
{
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
		{
			int dif = (i&1)==(j&1);
			c[k][clr] += (a[k][i][j]-'0') != (clr^dif);
		}
}

int main(void)
{
	scanf("%d",&n);
	for(int k=1; k<=4; ++k)
	{
		for(int i=1; i<=n; ++i) scanf("%s",a[k][i]+1);
		for(int i=0; i<=1; ++i) calc(k,i);
	}
	
	int ans=inf;
	for(int i=1; i<=4; ++i)
		for(int j=1; j<i; ++j)
		{
			int res=0;
			for(int k=1; k<=4; ++k)
				res += c[k][k==i || k==j];
			chk_min(ans,res);
		}
	printf("%d",ans);
	return 0;
}