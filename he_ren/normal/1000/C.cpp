#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MAXP = MAXN*4;

struct Seg
{
	ll l,r;
}a[MAXN];

ll dsc[MAXP];
int pcnt=0;

int dif[MAXP];
ll ans[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%lld%lld",&a[i].l,&a[i].r);
	
	for(int i=1; i<=n; ++i)
	{
		dsc[++pcnt]=a[i].l;
		dsc[++pcnt]=a[i].r;
		dsc[++pcnt]=a[i].l-1;
		dsc[++pcnt]=a[i].r+1;
	}
	sort(dsc+1,dsc+pcnt+1);
	pcnt=unique(dsc+1,dsc+pcnt+1)-dsc-1;
	for(int i=1; i<=n; ++i)
		a[i].l = lower_bound(dsc+1,dsc+pcnt+1, a[i].l) - dsc,
		a[i].r = lower_bound(dsc+1,dsc+pcnt+1, a[i].r) - dsc;
	
	for(int i=1; i<=n; ++i)
		++dif[a[i].l], --dif[a[i].r+1];
	
	for(int i=1; i<=pcnt; ++i)
		dif[i]+=dif[i-1];
	
	for(int i=1; i<=pcnt; ++i) ++ans[dif[i]];
	for(int i=2; i<=pcnt; ++i)
		if(dif[i]==dif[i-1])
			ans[dif[i]] += dsc[i]-dsc[i-1]-1;
	for(int i=1; i<=n; ++i) printf("%lld ",ans[i]);
	return 0;
}