#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e2 + 5;

int a[MAXN],b[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(int i=1; i<=n; ++i) printf("%d ",a[i]);
	putchar('\n');
	for(int i=1; i<=n; ++i) printf("%d ",b[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}