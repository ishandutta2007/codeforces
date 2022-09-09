#include<cstdio>
#include<cstring>
const int MAXN = 100 + 5;

int t[35];
#define lowbit(x) ((x)&-(x))

inline void solve()
{
	memset(t,0,sizeof(t));
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		for(int j=0; j<=29; ++j)
			if((x>>j)&1)
			{
				++t[j];
				break;
			}
	}
	
	for(int i=0; i<=11; ++i)
		t[i+1] += t[i]>>1;
	
	if(t[11]) printf("YES\n");
	else printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}