#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int MAXN = 20 + 5;

#define bbit(i) (1ll<<(i))
#define bdig(x,i) (((x)>>(i))&1)

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	ull fac = 1;
	for(int i=1; i<=(n>>1)-1; ++i) fac *= i;
	
	ull ans = 0;
	
	int all = (1<<n) - 1;
	for(int mask=0; mask<=all; ++mask)
	{
		if(mask&1) continue;
		
		int cnt = 0;
		for(int i=1; i<=n; ++i)
			if(bdig(mask, i-1))
				++cnt;
		if(cnt != (n>>1)) continue;
		
		ans += fac * fac;
	}
	
	printf("%llu\n",ans);
}

int main(void)
{
	int T = 1;
	while(T--) solve();
	return 0;
}