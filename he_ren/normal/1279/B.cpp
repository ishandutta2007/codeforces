#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

ll a[MAXN],sum[MAXN],mx[MAXN];

void solve(void)
{
	int n,s;
	scanf("%d%d",&n,&s);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	
	for(int i=1; i<=n; ++i)
	{
		sum[i] = sum[i-1] + a[i];
		if(a[i] > a[mx[i-1]]) mx[i]=i;
		else mx[i]=mx[i-1];
	}
	
	if(sum[n]<=s){ printf("0\n"); return;}
	int ans=0;
	for(int i=1; i<=n; ++i)
		if(sum[i]-a[mx[i]]<=s) ans=mx[i];
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}