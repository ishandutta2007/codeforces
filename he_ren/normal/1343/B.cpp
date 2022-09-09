#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

ll a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	int m = n>>1;
	if(m&1){ printf("NO\n"); return;}
	
	ll sum=0;
	for(int i=1; i<=m; ++i)
		a[i+m] =  2*i,
		sum += a[i+m];
	
	a[0]=-1;
	for(int i=1; i<m; ++i)
		a[i] = a[i-1] + 2,
		sum -= a[i];
	a[m] = sum;
	
	reverse(a+1,a+n+1);
	printf("YES\n");
	for(int i=1; i<=n; ++i) printf("%lld ",a[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}