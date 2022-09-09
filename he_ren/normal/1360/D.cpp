#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	
	int sqn = sqrt(n), ans=n;
	for(int i=1; i<=sqn; ++i)
	{
		if(n%i) continue;
		if(i <= d) ans = min(ans,n/i);
		if(n/i <= d) ans = min(ans,i);
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