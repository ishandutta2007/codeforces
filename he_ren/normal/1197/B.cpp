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
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int mx = 1;
	for(int i=1; i<=n; ++i)
		if(a[i] > a[mx]) mx = i;
	
	for(int i=1; i<mx; ++i)
		if(a[i] > a[i+1])
		{
			printf("NO\n");
			return;
		}
	for(int i=mx+1; i<=n; ++i)
		if(a[i] > a[i-1])
		{
			printf("NO\n");
			return;
		}
	printf("YES\n");
}

int main(void)
{
	int T=1;
	while(T--) solve();
	return 0;
}