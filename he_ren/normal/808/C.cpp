#include<cstdio>
#include<algorithm>
const int MAXN = 100 + 5;
using namespace std;

struct Node
{
	int x,id;
}a[MAXN];
inline bool cmp(Node &p,Node &q){ return p.x<q.x;}
int ans[MAXN];

int main(void)
{
	int n,w;
	scanf("%d%d",&n,&w);
	for(int i=1; i<=n; ++i)	
		scanf("%d",&a[i].x), a[i].id=i;
	
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; ++i)
	{
		int t = (a[i].x+1)>>1;
		if(w<t)
		{
			printf("-1");
			return 0;
		}
		
		ans[a[i].id] = t;
		w-=t; a[i].x-=t;
	}
	for(int i=n; i>=1; --i)
	{
		if(!w) break;
		ans[a[i].id] += min(w, a[i].x);
		w -= min(w, a[i].x);
	}
	
	for(int i=1; i<=n; ++i) printf("%d ",ans[i]);
	return 0;
}