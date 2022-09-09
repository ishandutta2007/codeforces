#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;
const int MAXA = (1<<20) + 5;

struct Node
{
	int a,b;
}p[MAXN];

int n;

int fa[MAXN<<1];
inline void init(int n){ for(int i=1; i<=n; ++i) fa[i] = i;}
int find(int u){ return fa[u]==u? u: fa[u]=find(fa[u]);}
inline void connect(int u,int v){ fa[find(u)] = find(v);}

struct Edge
{
	int next,to;
	int a,b;
}e[MAXN<<1];
int head[MAXA], etot=0, deg[MAXA];
inline void add(int u,int v,int a,int b)
{
	e[++etot]=(Edge){ head[u],v,a,b};
	head[u]=etot;
	++deg[v];
}

int cur[MAXA];
bool vis[MAXN];
vector<int> ans;

void dfs(int u)
{
	for(int &i=cur[u]; i; i=e[i].next)
		if(!vis[(i-1)>>1])
		{
			vis[(i-1)>>1]=1;
			
			int v = e[i].to, a = e[i].a, b = e[i].b;
			dfs(v);
			
			ans.push_back(b);
			ans.push_back(a);
		}
}

bool check(int mid)
{
	etot=0;
	memset(head,0,sizeof(head));
	memset(deg,0,sizeof(deg));
	
	int all = (1<<mid)-1;
	
	for(int i=1; i<=n; ++i)
	{
		int a = p[i].a & all;
		int b = p[i].b & all;
		add(a,b, i*2-1, i*2);
		add(b,a, i*2, i*2-1);
	}
	
	for(int i=0; i<=all; ++i)
		if(deg[i]&1) return 0;
	
	memset(vis,0,sizeof(vis));
	for(int i=0; i<=all; ++i)
		cur[i] = head[i];
	ans.clear();
	
	for(int i=0; i<=all; ++i)
		if(deg[i])
		{
			dfs(i);
			return (int)ans.size() == (n<<1);
		}
	return 1;
}

int val[MAXN<<1];

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&p[i].a,&p[i].b);
	
	int l=0, r=20;
	while(l<r)
	{
		int mid = (l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	
	check(l);
	
	printf("%d\n",l);
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d ",ans[i]);
	return 0;
}