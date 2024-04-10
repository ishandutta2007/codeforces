#include<cstdio>
#include<stack>
using namespace std;
typedef pair<int,int> pii;
#define fir first
#define sec second
#define Mp make_pair
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

int c[MAXN],a[MAXN];
bool vis[MAXN];

pii dfs(int u)
{
	static bool ins[MAXN];
	
	if(vis[u]) return Mp(0,0);
	
	vis[u]=ins[u]=1;
	pii res;
	if(ins[a[u]]) res = Mp(c[u],a[u]);
	else res = dfs(a[u]);
	
	if(res.sec) chk_min(res.fir,c[u]);
	if(res.sec==u) res.sec=0;
	
	ins[u]=0;
	return res;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&c[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int ans=0;
	for(int i=1; i<=n; ++i)
		if(!vis[i]) ans+=dfs(i).fir;
	printf("%d",ans);
	return 0;
}