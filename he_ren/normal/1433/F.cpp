#include<cstdio>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 70 + 5;
const int MAXM = 70 + 5;
const int MAXD = 70 + 5;
const int inf = 0x3f3f3f3f;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN][MAXM];

int f[MAXN][MAXD];

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			scanf("%d",&a[i][j]);
	
	for(int i=0; i<=n; ++i)
		for(int j=0; j<d; ++j)
			f[i][j] = -inf;
	f[0][0] = 0;
	
	for(int x=1; x<=n; ++x)
	{
		static int g[MAXM][MAXM][MAXD];
		for(int i=0; i<=m; ++i)
		{
			g[0][i][0] = 0;
			for(int j=1; j<d; ++j)
				g[0][i][j] = -inf;
		}
		
		int chs = m/2;
		for(int i=1; i<=m; ++i)
		{
			for(int j=0; j<=m; ++j)
				for(int k=0; k<d; ++k)
					g[i][j][k] = g[i-1][j][k];
			
			for(int j=0; j<i && j<chs; ++j)
				for(int k=0; k<d; ++k)
					chk_max(g[i][j+1][(k + a[x][i])%d], g[i-1][j][k] + a[x][i]);
			
			for(int k=0; k<d; ++k)
				for(int j=1; j<=m; ++j)
					chk_max(g[i][j][k], g[i][j-1][k]);
		}
		
		for(int i=0; i<d; ++i)
			for(int j=0; j<d; ++j)
				chk_max(f[x][(i+j)%d], f[x-1][j] + g[m][chs][i]);
	}
	
	printf("%d",f[n][0]);
	return 0;
}