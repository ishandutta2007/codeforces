#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 30 + 5;
const int LG = 64 + 5;

ll a[MAXN];
int t[LG];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	
	memset(t,0,sizeof(t));
	
	for(int i=1; i<=n; ++i)
	{
		int now=0;
		while(a[i])
			t[now++] += a[i]%d,
			a[i]/=d;
	}
	for(int i=0; i<LG; ++i)
		if(t[i]>1)
		{
			printf("NO\n");
			return;
		}
	printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}