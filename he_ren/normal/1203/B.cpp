#include<cstdio>
#include<algorithm>
typedef long long ll;
const int MAXN = 100 + 5;
using namespace std;

int a[MAXN*4];
ll b[MAXN*2];

inline void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n*4; ++i) scanf("%d",&a[i]);
	sort(a+1,a+n*4+1);
	for(int i=1; i<=n*4; i+=2)
	{
		if(a[i]==a[i+1])
		{
			b[(i>>1)+1] = a[i];
		}
		else
		{
			printf("NO\n");
			return;
		}
	}
	for(int i=2; i<=n; ++i)
	{
		if(b[i]*b[n*2-i+1] != b[i-1]*b[n*2-i+2])
		{
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}

int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}