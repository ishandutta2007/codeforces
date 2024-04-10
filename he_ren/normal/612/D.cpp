#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e6 + 5;
const int MAXP = MAXN*4;

struct Seg
{
	int l,r;
}a[MAXN],ans[MAXN];
int acnt=0;

int dsc[MAXP],cnt=0;
int b[MAXP];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i].l,&a[i].r);
	
	for(int i=1; i<=n; ++i)
	{
		a[i].l*=2; a[i].r*=2;
		dsc[++cnt]=a[i].l; dsc[++cnt]=a[i].r;
		dsc[++cnt]=a[i].l-1; dsc[++cnt]=a[i].r+1;
	}
	sort(dsc+1,dsc+cnt+1);
	cnt = unique(dsc+1,dsc+cnt+1)-dsc-1;
	for(int i=1; i<=n; ++i)
		a[i].l = lower_bound(dsc+1,dsc+cnt+1,a[i].l)-dsc,
		a[i].r = lower_bound(dsc+1,dsc+cnt+1,a[i].r)-dsc;
	
	for(int i=1; i<=n; ++i)
		++b[a[i].l], --b[a[i].r+1];
	
	int now=0;
	bool flag=0;
	for(int i=1; i<=cnt; ++i)
	{
		now+=b[i];
		if(now>=d)
		{
			if(!flag) ans[++acnt].l = dsc[i]/2;
			flag=1;
		}
		if(now<d)
		{
			if(flag) ans[acnt].r = dsc[i-1]/2;
			flag=0;
		}
	}
	printf("%d\n",acnt);
	for(int i=1; i<=acnt; ++i) printf("%d %d\n",ans[i].l,ans[i].r);
	return 0;
}