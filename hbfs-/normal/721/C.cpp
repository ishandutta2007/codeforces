#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define N 5005
#define M 5005

using namespace std;

struct Edge{ int a,b,v,next; }e[M];
int head[N],rd[N],out[N],cnt,n,m,t,top;
int dis[N][N],pre[N][N];
queue<int> q;

inline void add_Edge(int a,int b,int v) {
	e[++cnt].a = a;
	e[cnt].b = b;
	e[cnt].v = v;
	e[cnt].next = head[a];
	head[a] = cnt;
	return ;
}

int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for (int i=1;i<=m;i++) {
		int a,b,v;
		scanf("%d%d%d",&a,&b,&v);
		add_Edge(a,b,v);
		rd[b]++; 
	}
	
	for (int i=1;i<=n;i++) if (rd[i] == 0) q.push(i);
	
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++)
			dis[i][j] = 1000000007;
	dis[1][1] = 0;
	
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i=head[u];i;i=e[i].next) {
			int v = e[i].b;
			int cp = e[i].v;
			for (int j=1;j<=n;j++) {
				if (dis[u][j-1] + cp < dis[v][j]) {
					pre[v][j] = 10000*u + j-1;
					dis[v][j] = dis[u][j-1] + cp;
				}
			}
			if (--rd[v] == 0) q.push(v);
		}
	}
	
	int ans = -1 , p = n;
	for (int j=1;j<=n;j++)
		if (dis[n][j] <= t)
			ans = j;
	printf("%d\n",ans);
	
	while (p != 0) {
		out[++top] = p;
		int p1 = pre[p][ans] / 10000 , p2 = pre[p][ans] % 10000;
		p = p1; ans = p2;
	}
	
	printf("%d",out[top]);
	for (int i=top-1;i>=1;i--) printf(" %d",out[i]);
	printf("\n");
	
	return 0;
}