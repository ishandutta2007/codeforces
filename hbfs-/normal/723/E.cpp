#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

#define N 550
#define M 550*550

using namespace std;

inline int read()
{
	int s = 0; char c; while((c=getchar())<'0'||c>'9');
	do{s=s*10+c-'0';}while((c=getchar())>='0'&&c<='9');
	return s;
}

int head[N],cnt = 1;
int n,m,deg[N],vis[N];
struct Edge{ int u,v,next,fx; }e[M];
vector<int> road;

inline void add_Edge(int u,int v) {
	e[++cnt].u = u;
	e[cnt].v = v;
	e[cnt].next = head[u];
	e[cnt].fx = 0;
	head[u] = cnt;
	return ;
}

bool DFS1(int u) {
	vis[u] = true; 
	for (int i=head[u];i;i=e[i].next) 
		if (e[i].fx == 0 && !vis[ e[i].v ]) {
			if (deg[ e[i].v ] % 2 || DFS1( e[i].v )) {
				road.push_back(i);
				return true;
			}
		}
	return false;
} 

void DFS2(int u) {
	for (int i=head[u];i;i=e[i].next) {
		if (e[i].fx == 0) {
			e[i].fx = 1;
			e[i^1].fx = -1;
			DFS2(e[i].v);
		}
	}
}

inline void init() {
	memset(deg,0,sizeof(deg));
	memset(head,0,sizeof(head));
	memset(e,0,sizeof(e));
	cnt = 1;
}

int main() 
{
	int T = 0; scanf("%d",&T);
	while (T--) {
		init();
		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;i++) {
			int u = read() , v = read();
			add_Edge(u,v); add_Edge(v,u);
			deg[u]++; deg[v]++;
		}
		
		int ans = 0;
		for (int i=1;i<=n;i++) if (deg[i] % 2 == 0) ans++;
		printf("%d\n",ans);
		
		bool flag = true;
		while (flag) {
			flag = false;
			for (int i=1;i<=n;i++) 
				if (deg[i] % 2 == 1) {
					memset(vis,0,sizeof(vis));
					flag = true;
					DFS1(i);
					
					for (int j=0;j<road.size();j++) {
						int tmp = road[j];
						e[tmp].fx = 1;
						e[tmp^1].fx = -1;
						deg[ e[tmp].u ]--;
						deg[ e[tmp].v ]--;
					}
					road.clear();
				}
		}
		
		for (int i=1;i<=n;i++) DFS2(i);
		
		for (int i=2;i<=cnt;i++) if (e[i].fx == 1)
			printf("%d %d\n",e[i].u,e[i].v);
		
	}
	return 0;
}