#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 5;

int deg[MAXN];

void solve(void)
{
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1; i<=n; ++i) deg[i] = 0;
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		++deg[u]; ++deg[v];
	}
	
	if(deg[x]<=1) printf("Ayush\n");
	else
	{
		if((n-3)%2) printf("Ayush\n");
		else printf("Ashish\n");
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}