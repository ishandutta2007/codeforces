#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int a[MAXN];

int main(void)
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static int pre[MAXN];
	for(int i=1; i<=n; ++i)
		pre[i] = pre[i-1] + (a[i] >= 0);
	
	static int suf[MAXN];
	for(int i=n; i>=1; --i)
		suf[i] = suf[i+1] + (a[i] <= 0);
	
	int ans = inf;
	for(int i=1; i<n; ++i)
		ans = min(ans, pre[i] + suf[i+1]);
	
	printf("%d",ans);
	return 0;
}