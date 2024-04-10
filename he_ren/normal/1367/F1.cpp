#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 3e3 + 5;
const int inf = 0x3f3f3f3f;

int a[MAXN];

int dsc[MAXN],cnt=0;

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	cnt = 0;
	for(int i=1; i<=n; ++i)
		dsc[++cnt] = a[i];
	sort(dsc+1,dsc+cnt+1);
	cnt = unique(dsc+1,dsc+cnt+1) - dsc - 1;
	for(int i=1; i<=n; ++i)
		a[i] = lower_bound(dsc+1,dsc+cnt+1,a[i]) - dsc;
	
	int ans = n-1;
	for(int i=1; i<=n; ++i)
	{
		int tmp = 1;
		
		int x=0;
		for(int j=i+1; j<=n; ++j)
			if(a[j]<a[i]) x = max(x, a[j]);
		
		int now = a[i]-1;
		for(int j=i-1; j>=1 && now>=x; --j)
			if(a[j]==now) --now, ++tmp;
		
		x=cnt+1;
		for(int j=1; j<i; ++j)
			if(a[j]>a[i]) x = min(x,a[j]);
		
		now = a[i]+1;
		for(int j=i+1; j<=n && now<=x; ++j)
			if(a[j]==now) ++now, ++tmp;
		
		ans = min(ans, n-tmp);
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