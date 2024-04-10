#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 50 + 5;

int a[MAXN], t[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int ans = 0;
	for(int k=2; k<=n*2; ++k)
	{
		memset(t,0,sizeof(t));
		for(int i=1; i<=n; ++i) ++t[a[i]];
		
		int res = 0;
		for(int i=1; i<=n; ++i)
		{
			if(k-i<1 || k-i>n) continue;
			
			if(k-i == i)
			{
				res += t[i]/2;
				t[i]%=2;
				continue;
			}
			int use = min(t[i], t[k-i]);
			res += use;
			t[i] -= use;
			t[k-i] -= use;
		}
		ans = max(ans, res);
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