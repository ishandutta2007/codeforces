#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;
const int MAXM = 1e2 + 5;

int a[MAXN][MAXM];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			scanf("%d",&a[i][j]);
	
	static int xsum[MAXN + MAXM];
	memset(xsum,0,sizeof(xsum));
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			xsum[i + j] ^= a[i][j];
	
	for(int i=1; i<=n+m; ++i)
		if(xsum[i]){ printf("Ashish\n"); return;}
	printf("Jeel\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}