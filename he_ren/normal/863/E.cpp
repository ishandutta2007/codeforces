#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXS = MAXN*3;
const int inf = 0x3f3f3f3f;

inline int min(int a,int b){ return a<b? a: b;}
inline void chk_min(int &a,int b){ if(a>b) a=b;}

struct Seg
{
	int l,r;
}a[MAXN];

int to[MAXS],cnt=0,t[MAXS],s[MAXS];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i].l,&a[i].r);
	
	for(int i=1; i<=n; ++i)
	{
		to[++cnt]=a[i].l;
		to[++cnt]=a[i].r;
		to[++cnt]=a[i].l-1;
	}
	sort(to+1,to+cnt+1);
	cnt = unique(to+1,to+cnt+1)-to-1;
	for(int i=1; i<=n; ++i)
	{
		a[i].l = lower_bound(to+1,to+cnt+1,a[i].l)-to;
		a[i].r = lower_bound(to+1,to+cnt+1,a[i].r)-to;
		//printf("%d %d\n",a[i].l,a[i].r);
	}
	
	for(int i=1; i<=n; ++i)
	{
		++t[a[i].l];
		--t[a[i].r+1];
	}
	for(int i=1; i<=cnt; ++i)
	{
		t[i]+=t[i-1];
		s[i] = s[i-1]+(t[i]==1);
		//printf("%d\n",t[i]);
	}
	
	for(int i=1; i<=n; ++i)
		if(s[a[i].r]-s[a[i].l-1] == 0)
		{
			printf("%d",i);
			return 0;
		}
	printf("-1");
	return 0;
}