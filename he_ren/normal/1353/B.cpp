#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 30 + 5;

int a[MAXN],b[MAXN];
int suma[MAXN], sumb[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	reverse(b+1,b+n+1);
	
	for(int i=1; i<=n; ++i)
		suma[i] = suma[i-1] + a[i];
	for(int i=1; i<=n; ++i)
		sumb[i] = sumb[i-1] + b[i];
	
	int ans = suma[n];
	for(int i=1; i<=d; ++i)
	{
		int tmp = suma[n] - suma[i] + sumb[i];
		if(ans < tmp) ans=tmp;
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