#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int k=2; (1ll<<k)-1<=n; ++k)
	{
		int pw = (1<<k)-1;
		if(n%pw==0)
		{
			printf("%d\n",n/pw);
			return;
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