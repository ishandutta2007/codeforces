#include<cstdio>
const int MAXN = 1e2 + 5;
const int MAXM = 1e2 + 5;

inline int min(int a,int b){ return a<b? a: b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN][MAXM],s[MAXN][MAXM];

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) scanf("%d",&a[i][j]);
	
	for(int j=1; j<=m; ++j)
		for(int i=1; i<=n; ++i)
			s[i][j] = s[i-1][j]+a[i][j];
	
	int ans=0, tot=0;
	for(int j=1; j<=m; ++j)
	{
		int res=0,del=0,cnt=0;
		for(int i=1; i<=n; ++i)
			if(a[i][j])
			{
				int tmp = s[min(i+d-1, n)][j]-s[i-1][j];
				if(tmp>res)
				{
					res=tmp;
					del=cnt;
				}
				++cnt;
			}
		ans+=res; tot+=del;
	}
	printf("%d %d",ans,tot);
	return 0;
}