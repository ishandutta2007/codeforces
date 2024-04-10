#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int MAXP = MAXN*4;

struct Node
{
	int l,r;
}a[MAXN];

int dsc[MAXP],cnt=0;
ll b[MAXP];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&a[i].l,&a[i].r);
	
	cnt=0;
	for(int i=1; i<=n; ++i)
	{
		a[i].l<<=1; a[i].r<<=1;
		dsc[++cnt]=a[i].l;
		dsc[++cnt]=a[i].r;
		dsc[++cnt]=a[i].l-1;
		dsc[++cnt]=a[i].r+1;
	}
	sort(dsc+1,dsc+cnt+1);
	cnt=unique(dsc+1,dsc+cnt+1)-dsc-1;
	for(int i=1; i<=n; ++i)
		a[i].l=lower_bound(dsc+1,dsc+cnt+1,a[i].l)-dsc,
		a[i].r=lower_bound(dsc+1,dsc+cnt+1,a[i].r)-dsc;
	
	for(int i=1; i<=cnt; ++i) b[i]=0;
	for(int i=1; i<=n; ++i)
		++b[a[i].l],
		--b[a[i].r+1];
	for(int i=1; i<=cnt; ++i)
		b[i]+=b[i-1];
	for(int i=1; i<=cnt; ++i)
		b[i]+=b[i-1];
	
	for(int i=1; i<=cnt; ++i)
		if(!(b[i]-b[i-1]) && b[i-1] && b[cnt]-b[i])
		{
			for(int j=1; j<=n; ++j)
				if(a[j].r<i) printf("1 ");
				else printf("2 ");
			putchar('\n');
			return;
		}
	printf("-1\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}