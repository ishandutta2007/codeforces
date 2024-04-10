#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e7 + 5;

int h,g;
int a[MAXN],dep[MAXN];
vector<int> ans;
#define ls(u) ((u)<<1)
#define rs(u) ((u)<<1|1)

bool canDel(int u)
{
	if(dep[u]>g) return 1;
	if(!a[ls(u)] && !a[rs(u)]) return 0;
	if(a[ls(u)] > a[rs(u)]) return canDel(ls(u));
	else return canDel(rs(u));
}

void erase(int u)
{
	if(!a[ls(u)] && !a[rs(u)]){ a[u]=0; return;}
	if(a[ls(u)] > a[rs(u)])
	{
		a[u] = a[ls(u)];
		erase(ls(u));
		return;
	}
	else
	{
		a[u] = a[rs(u)];
		erase(rs(u));
		return;
	}
}

void solve(int u)
{
	while(a[u] && canDel(u))
		ans.push_back(u),
		erase(u);
	if(!a[u]) return;
	if(a[ls(u)]) solve(ls(u));
	if(a[rs(u)]) solve(rs(u));
}

void solve(void)
{
	scanf("%d%d",&h,&g);
	int n = (1<<h)-1;
	int m = (1<<g)-1;
	for(int i=1; i<=rs(n); ++i) a[i]=0;
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	dep[1]=1;
	for(int i=2; i<=n; ++i)
		dep[i] = dep[i>>1]+1;
	
	ans.clear();
	solve(1);
	
	ll sum=0;
	for(int i=1; i<=m; ++i) sum += a[i];
	printf("%lld\n",sum);
	for(int i=0; i<(int)ans.size(); ++i) printf("%d ",ans[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}