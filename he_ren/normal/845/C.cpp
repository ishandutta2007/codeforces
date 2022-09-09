#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 5;

inline void NO(void){ printf("NO"); exit(0);}

struct Seg
{
	int l,r;
}a[MAXN];
inline bool cmp(const Seg &p,const Seg &q){ return p.l!=q.l? p.l<q.l: p.r<q.r;}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i].l,&a[i].r);
	
	sort(a+1,a+n+1,cmp);
	int x=0, y=0;
	a[0]=(Seg){-1,-1};
	for(int i=1; i<=n; ++i)
	{
		if(a[i].l > a[x].r) x=i;
		else if(a[i].l > a[y].r) y=i;
		else NO();
	}
	printf("YES");
	return 0;
}