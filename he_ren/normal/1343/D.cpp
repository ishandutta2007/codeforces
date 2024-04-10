#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MAXD = 4e5 + 5;

int a[MAXN],b[MAXN];
int eq[MAXD],dif[MAXD];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	n>>=1;
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=n; i>=1; --i) scanf("%d",&b[i]);
	
	for(int i=1; i<=(d<<1); ++i) eq[i] = dif[i] = 0;
	
	for(int i=1; i<=n; ++i) ++eq[ a[i]+b[i] ];
	for(int i=1; i<=n; ++i)
	{
		int l = min(a[i],b[i])+1;
		int r = max(a[i],b[i])+d;
		++dif[l]; --dif[r+1];
	}
	for(int i=1; i<=(d<<1); ++i) dif[i] += dif[i-1];
	
	int ans = n<<1;
	for(int i=2; i<=(d<<1); ++i)
	{
		int tmp = 2*(n-dif[i]) + dif[i] - eq[i];
		ans = min(ans,tmp);
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