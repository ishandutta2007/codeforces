#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int ALL = (1<<4) + 5;
const int all = 1<<4;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const char hard[] = "hard";

#define bit(x,i) (((x)>>(i))&1)

inline void chk_min(ll &a,ll b){ if(a>b) a=b;}

char s[MAXN];
int a[MAXN];
ll f[MAXN][4 + 3];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<4; ++j)
		{
			ll &now = f[i][j] = linf;
			if(s[i]==hard[j])
			{
				if(j) chk_min(now, f[i-1][j-1]);
				chk_min(now, f[i-1][j] + a[i]);
			}
			else now = f[i-1][j];
		}
	}
	printf("%lld",f[n][3]);
	return 0;
}