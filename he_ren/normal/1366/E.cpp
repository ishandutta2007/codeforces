#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int a[MAXN], b[MAXM];
int mnr[MAXM], rpos[MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i]);
	b[m+1] = inf;
	
	for(int i=1; i<=n; ++i)
	{
		int pos = upper_bound(b+1,b+m+1, a[i]) - b;
		if(pos == 1){ printf("0"); return 0;}
		
		--pos;
		mnr[pos] = max(mnr[pos], i);
		if(a[i] == b[pos])
			rpos[pos] = i;
	}
	
	for(int i=1; i<=m; ++i)
		if(mnr[i] <= mnr[i-1] || rpos[i] <= mnr[i-1])
		{
			printf("0");
			return 0;
		}
	
	ll ans = 1;
	for(int i=1; i<m; ++i)
		ans = ans * (rpos[i+1] - mnr[i]) %mod;
	printf("%lld",ans);
	return 0;
}