#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = (1<<18) + 5;
const int LB = 18 + 5;
const ll linf = 0x3f3f3f3f3f3f;

int a[MAXN];
int siz[LB], sum[LB];
ll f[LB];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; a[i] != -1; ++i) a[i] = 0;
	
	int m = 0;
	for(int cur=n>>1; cur; cur>>=1)
		siz[++m] = cur, sum[m] = sum[m-1] + siz[m];
	
	memset(f,0x3f,sizeof(f));
	f[0] = 0;
	for(int i=n, cnt = 0; i>=1; --i) if(a[i] != -1)
	{
		++cnt;
		for(int j=m; j>=1; --j)
			f[j] = min(f[j], f[j-1] + a[i]);
		for(int j=0; j<=m; ++j)
			if(sum[j] < cnt) f[j] = linf;
	}
	
	printf("%lld",f[m]);
	return 0;
}