#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN];

void solve(void)
{
	int h,n;
	scanf("%d%d",&h,&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	a[n+1] = 0;
	
	int ans = 0;
	for(int i=2; i<=n; ++i)
	{
		if(a[i] == a[i+1]+1) ++i;
		else ++ans;
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