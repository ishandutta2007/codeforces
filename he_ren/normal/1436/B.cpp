#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

int a[MAXN][MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	memset(a,0,sizeof(a));
	for(int i=1; i<=n; ++i)
	{
		a[i][i] = 1;
		if(i == n) a[i][1] = 1;
		else a[i][i+1] = 1;
	}
	
	for(int i=1; i<=n; ++i, putchar('\n'))
		for(int j=1; j<=n; ++j)
			printf("%d ",a[i][j]);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}