#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=1; i<=n; ++i,putchar('\n'))
	{
		for(int j=1; j<=m; ++j)
		{
			if(i==1 && j==1) putchar('W');
			else putchar('B');
		}
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}