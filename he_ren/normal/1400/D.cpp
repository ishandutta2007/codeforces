#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e3 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll ans = 0;
	for(int i=1; i<=n; ++i)
	{
		static int cntl[MAXN], cntr[MAXN];
		for(int j=1; j<=n; ++j) cntl[j] = cntr[j] = 0;
		for(int j=i+2; j<=n; ++j) ++cntr[a[j]];
		
		ll cur = 0;
		for(int j=i+1; j<n; ++j)
		{
			if(a[j] == a[i]) ans += cur;
			
			
			cur -= cntl[a[j+1]]; --cntr[a[j+1]];
			cur += cntr[a[j]]; ++cntl[a[j]];
		}
	}
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}