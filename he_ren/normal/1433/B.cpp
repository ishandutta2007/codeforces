#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 50 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int ans = 0;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && a[i] == a[j]) ++j;
		if(a[i]) continue;
		if(i > 1 && a[i-1] && j<=n && a[j])
			ans += j-i;
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