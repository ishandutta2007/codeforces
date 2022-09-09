#include<cstdio>
#include<set>
const int MAXN = 3e5 + 5;
const int MAXA = 1e9 + 5;
using namespace std;

struct Seg
{
	int l,r;
}ans[MAXN];
int cnt=0;

int a[MAXN];
set<int> t;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int l=1,r; l<=n;)
	{
		r=l;
		while(r<=n && t.find(a[r])==t.end())
		{
			t.insert(a[r]);
			++r;
		}
		if(r>n)
		{
			ans[cnt].r=n;
			break;
		}
		ans[++cnt] = (Seg){l,r};
		for(; l<=r; ++l) t.erase(a[l]);
	}
	
	if(!cnt) printf("-1");
	else
	{
		printf("%d\n",cnt);
		for(int i=1; i<=cnt; ++i) printf("%d %d\n",ans[i].l,ans[i].r);
	}
	return 0;
}