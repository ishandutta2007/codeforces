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
	
	int ans = 0;
	while(ans * (ans+1) / 2 < x) ++ans;
	
	if(ans * (ans+1) / 2 == x+1) ++ans;
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}