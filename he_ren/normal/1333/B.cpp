#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

int a[MAXN],b[MAXN];
bool f[MAXN],g[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	for(int i=1; i<=n; ++i) f[i] = f[i-1] | (a[i]==1);
	for(int i=1; i<=n; ++i) g[i] = g[i-1] | (a[i]==-1);
	
	for(int i=n; i>=1; --i)
	{
		if(a[i] < b[i] && !f[i-1]){ printf("NO\n"); return;}
		if(a[i] > b[i] && !g[i-1]){ printf("NO\n"); return;}
	}
	printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}