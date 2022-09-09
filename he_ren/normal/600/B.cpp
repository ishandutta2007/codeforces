#include<cstdio>
#include<algorithm>
const int MAXN = 2e5 + 5;
using namespace std;

struct Node
{
	int x,id;
}b[MAXN];
inline bool cmp(const Node &a,const Node &b){ return a.x<b.x;}
int a[MAXN],ans[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i].x), b[i].id=i;
	
	sort(a+1,a+n+1);
	sort(b+1,b+m+1,cmp);
	for(int i=1,j=1; i<=m; ++i)
	{
		while(j<=n && a[j]<=b[i].x) ++j;
		ans[b[i].id] = j-1;
	}
	
	for(int i=1; i<=m; ++i) printf("%d ",ans[i]);
	return 0;
}