#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 5;

int a[MAXN];

void solve(void)
{
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int cnt[2] = {0,0};
	for(int i=1; i<=n; ++i)
		++cnt[a[i]%2];
	
	for(int i=0; i<=cnt[0] && i<=x; ++i)
	{
		int j = x-i;
		if(j>cnt[1]) continue;
		if(j%2==1)
		{
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}