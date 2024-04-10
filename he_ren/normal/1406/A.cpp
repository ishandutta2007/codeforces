#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	
	int ans = 0;
	
	bool flagb = 1;
	a[0] = -1;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && a[j] == a[i]) ++j;
		
		if(a[i] != a[i-1]+1)
		{
			ans += a[i-1]+1;
			if(flagb) ans *= 2;
			break;
		}
		if(j-i == 1 && flagb)
		{
			flagb = 0,
			ans += a[i];
		}
		if(j > n)
		{
			ans += a[i]+1;
			if(flagb) ans *= 2;
		}
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