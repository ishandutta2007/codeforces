#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int x;
	scanf("%d",&x);
	
	int ans = (x%10 - 1) * 4 * 5 / 2;
	int cnt = 0;
	while(x)
		++cnt,
		x/=10;
	printf("%d\n",ans + cnt * (cnt+1) / 2);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}