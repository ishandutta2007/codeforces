#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 5e2 + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

int a[MAXN];
int f[MAXN][MAXN],g[MAXN][MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		for(int j=i; j<=n; ++j)
		{
			f[i][j]=j-i+1;
			if(i==j) g[i][j]=a[i];
		}
	
	for(int len=2; len<=n; ++len)
		for(int i=1; i+len-1<=n; ++i)
		{
			int j=i+len-1;
			for(int k=i; k<j; ++k)
			{
				chk_min(f[i][j], f[i][k]+f[k+1][j]);
				if(f[i][k]==1 && f[k+1][j]==1 && g[i][k]==g[k+1][j])
					f[i][j] = 1,
					g[i][j] = g[i][k]+1;
			}
		}
	
	printf("%d",f[1][n]);
	return 0;
}