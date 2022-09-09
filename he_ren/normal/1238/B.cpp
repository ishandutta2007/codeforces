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
	int n,r;
	scanf("%d%d",&n,&r);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	n = unique(a+1,a+n+1)-a-1;
	
	ll sum = 0;
	int ans = 0;
	for(int i=n; i>=1; --i)
	{
		if(a[i] - sum <= 0) break;
		++ans;
		sum += r;
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