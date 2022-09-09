#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 5;

int p[100] = {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43};

int a[MAXN],c[MAXN];
int dsc[MAXN],cnt=0;

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	cnt=0;
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=11; ++j)
			if(a[i]%p[j] == 0)
			{
				c[i]=j;
				dsc[++cnt]=j;
				break;
			}
	}
	
	sort(dsc+1,dsc+cnt+1);
	cnt = unique(dsc+1,dsc+cnt+1)-dsc-1;
	for(int i=1; i<=n; ++i)
		c[i] = lower_bound(dsc+1,dsc+cnt+1,c[i])-dsc;
	
	printf("%d\n",cnt);
	for(int i=1; i<=n; ++i) printf("%d ",c[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}