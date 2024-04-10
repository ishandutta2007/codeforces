#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e3 + 5;

struct Node
{
	int x,id;
}a[MAXN];
inline bool cmp(const Node &p,const Node &q){ return p.x<q.x;}

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i].x), a[i].id=i;
	if(n==2 || m<n){ printf("-1\n"); return;}
	
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=1; i<=n; ++i) ans += a[i].x<<1;
	ans += (m-n)*(a[1].x+a[2].x);
	
	printf("%d\n",ans);
	for(int i=1; i<n; ++i)
		printf("%d %d\n",i,i+1);
	printf("%d 1\n",n);
	for(int i=n+1; i<=m; ++i) printf("%d %d\n",a[1].id,a[2].id);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}