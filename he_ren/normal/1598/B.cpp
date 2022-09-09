#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		a[i] = 0;
		for(int j=0; j<5; ++j)
		{
			int x;
			scanf("%d",&x);
			a[i] |= x << j;
		}
	}
	
	for(int x=0; x<5; ++x)
		for(int y=0; y<x; ++y)
		{
			static int cnt[2][2];
			memset(cnt, 0, sizeof(cnt));
			for(int i=1; i<=n; ++i)
				++cnt[bdig(a[i], x)][bdig(a[i], y)];
			
			if(cnt[0][0]) continue;
			int p = cnt[0][1], q = cnt[1][0];
			if(min(p,q) + cnt[1][1] >= max(p,q))
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