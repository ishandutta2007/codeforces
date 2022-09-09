#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

int gcd(int a,int b){ return b? gcd(b,a%b): a;}

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static bool vis[MAXN];
	for(int i=1; i<=n; ++i) vis[i] = 0;
	
	int mxi = 1;
	for(int i=1; i<=n; ++i)
		if(a[i] > a[mxi]) mxi = i;
	vis[mxi] = 1;
	
	int cur = a[mxi];
	printf("%d ",a[mxi]);
	for(int k=2; k<=n; ++k)
	{
		int mxi = -1;
		for(int i=1; i<=n; ++i) if(!vis[i])
			if(mxi == -1 || gcd(cur,a[i]) > gcd(cur,a[mxi]))
				mxi = i;
		vis[mxi] = 1;
		
		cur = gcd(cur, a[mxi]);
		printf("%d ",a[mxi]);
	}
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}