#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	bool flag = 0;
	for(int i=1; i<=n; ++i)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(b == c) flag = 1;
	}
	
	if(m%2 || !flag) printf("NO\n");
	else printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}