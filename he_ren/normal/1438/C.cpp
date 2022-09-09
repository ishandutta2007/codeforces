#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i, putchar('\n'))
		for(int j=1; j<=m; ++j)
		{
			int x;
			scanf("%d",&x);
			if((x&1) != ((i^j)&1)) ++x;
			printf("%d ",x);
		}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}