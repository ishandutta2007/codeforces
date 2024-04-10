#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static int freq[MAXN];
	for(int i=1; i<=n; ++i) freq[i] = 0;
	for(int i=1; i<=n; ++i) ++freq[a[i]];
	for(int i=1; i<=n; ++i)
		if(freq[i] > ((n+1)>>1)){ printf("-1\n"); return;}
	
	static int cnt[MAXN];
	for(int i=1; i<=n; ++i) cnt[i] = 0;
	
	int tot = 1;
	++cnt[a[1]]; ++cnt[a[n]];
	for(int i=1; i<n; ++i)
		if(a[i] == a[i+1])
			++cnt[a[i]], ++cnt[a[i+1]], ++tot;
	
	int mx = 0;
	for(int i=1; i<=n; ++i)
		mx = max(mx, cnt[i]);
	
	printf("%d\n",tot + max(0, mx - (tot+1)) - 1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}