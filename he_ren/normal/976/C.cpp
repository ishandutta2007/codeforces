#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int,int> pii;
#define mp make_pair
#define fir first
#define sec second
const int MAXN = 3e5 + 5;
const int inf = 0x3f3f3f3f;

struct Seg
{
	int id,l,r;
}a[MAXN];
inline bool cmp(const Seg &p,const Seg &q){ return p.r==q.r? p.l>q.l: p.r<q.r;}

set<pii> t;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		a[i]=(Seg){ i,l,r};
	}
	
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; ++i)
	{
		set<pii>::iterator it = t.lower_bound(mp(a[i].l,-inf));
		if(it!=t.end())
		{
			printf("%d %d",it->sec,a[i].id);
			return 0;
		}
		t.insert(mp(a[i].l,a[i].id));
	}
	printf("-1 -1");
	return 0;
}