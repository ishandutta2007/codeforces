#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll linf = 0x3f3f3f3f3f3f3f3f;

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	int ans = n-1;
	for(int i=1; i<=40000; ++i)
	{
		ans = min(ans, i-1 + (n-i + i-1)/i);
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}