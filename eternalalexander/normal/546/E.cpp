#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 10005
#define maxm 200005
#define inf 2147483647

struct edge {
    int u, v,  c, next, tag;
}edges[maxm];
int n, m, temp1, temp2;
int tail = 1;
int head[maxn], depth[maxn], in[maxn]={0}, out[maxn]={0};
int graph[200][200];
int s, t;
void add_edge(int u, int v, int c, int tag=0) {
    edges[tail].next=head[u];
	edges[tail].u=u;
	edges[tail].tag=tag;
    head[u]=tail;
    edges[tail].v=v;
    edges[tail++].c=c;
} inline int bfs() {
    int queue[maxn];
    int front=0; int back=1;
    queue[front]=s; int u;
    memset(depth, 0, sizeof(depth));
    depth[s]=1; queue[0]=s;
    while (front<back) {
        u=queue[front++];
        for (int i = head[u]; i; i=edges[i].next) {
            if (edges[i].c>0&&depth[edges[i].v]==0) {
                depth[edges[i].v]=depth[u]+1;
                queue[back++]=edges[i].v;
            }
        }
    } if (depth[t]==0) return 0;
    return 1;
} int dfs(int u, int f) {
    if (u==t) return f;
    for (int i = head[u]; i; i=edges[i].next) {
        if (depth[edges[i].v]==depth[u]+1&&edges[i].c!=0) {
            int d = dfs(edges[i].v, std::min(f, edges[i].c));
            if (d>0) {
                edges[i].c-=d;
                edges[((i-1)^1)+1].c+=d;
                return d;
            }
        }
    } return 0;
}int Dinic() {
    int ans = 0; int d;
    while (bfs()) {
        while (d=dfs(s, inf)) {
            ans+=d;
        }
    }return ans;
} 

int a[200], b[200];

int main() {
	int u, v, tot=0, tot2=0;
	scanf("%d %d", &n, &m);
	for (int i=1;i<=n;++i) {scanf("%d", &a[i]); tot2+=a[i];}
	for (int i=1;i<=n;++i) {scanf("%d", &b[i]); tot+=b[i];}
	if (tot2!=tot) {printf("NO"); return 0;}
	s=3000;t=3001;
	for (int i=1;i<=n;++i) {
		add_edge(s, i*3, a[i]); add_edge(i*2, s, 0);
		add_edge(i*3, i*3+1, inf); add_edge(i*3+1, i*3, 0);
		add_edge(i*3, i*3+2, inf, 2); add_edge(i*3+2, i*3, 0);
		add_edge(i*3+2, t, b[i]); add_edge(t, i*3+2, 0);
	} for (int i=1;i<=m;++i) {
		scanf("%d %d", &u, &v);
		add_edge(u*3+1, v*3+2, inf, 1); add_edge(v*3+2, u*3+1, 0);
		std::swap(u, v);
		add_edge(u*3+1, v*3+2, inf, 1); add_edge(v*3+2, u*3+1, 0);
	} int d= Dinic();
	if (d==tot) {
		printf("YES\n");
		for (int i=1;i<tail;i+=2) {
			if (!edges[i].tag) continue;
			u=edges[i].u/3; v=edges[i].v/3;
			//printf("%d %d %d\n", u, v, edges[i+1].c);
			if (edges[i].tag==1) graph[u][v]+=edges[i+1].c;
			if (edges[i].tag==2) graph[u][u]+=edges[i+1].c;
		}for (int i=1;i<=n;++i) {for (int j=1;j<=n;++j) printf("%d ", graph[i][j]); printf("\n");}
	}else {
		printf("NO");
	}
	return 0;
}