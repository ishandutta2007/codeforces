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
	int sum = 0;
	for(int i=1; i<=n; ++i)
	{
		int a;
		scanf("%d",&a);
		sum += a;
	}
	
	if(sum == m) printf("YES\n");
	else printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}