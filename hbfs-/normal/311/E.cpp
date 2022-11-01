#include <bits/stdc++.h>
#define INF 2147483647
#define N 40050
#define M 400050
using namespace std;

inline int rd() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int h[N],p[N],cur[N],S,T,cnt=1,tot;
int g[N],v[N],l[N],n,m,G,ans;
struct Edge{ int u,cap,next; }e[M];
void add(int a,int b,int v) {
	e[++cnt] = (Edge){b,v,h[a]}, h[a] = cnt;
	e[++cnt] = (Edge){a,0,h[b]}, h[b] = cnt;
}

bool BFS() {
	bool flag = false;
	memset(p,0,sizeof(p));
	for (int i=1;i<=tot;i++) cur[i] = h[i];
	queue<int> q;
	p[S] = 1;
	q.push(S);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == T) flag = true;
		for (int i=h[u];i;i=e[i].next) {
			int v = e[i].u, cp = e[i].cap;
			if (p[v] == 0 && cp > 0)
				p[v] = p[u] + 1, q.push(v);
		}
	}
	return flag;
}

int DFS(int u,int flow) {
	if (u == T) return flow;
	int g = 0 , f = flow;
	for (int i=cur[u];i;i=e[i].next) {
		cur[u] = i;
		int v = e[i].u, cp = e[i].cap, tmp = 0;
		if (p[v] == p[u]+1 && cp > 0 && ( tmp = DFS(v,min(f,cp)) ) > 0) {
			g += tmp, f -= tmp;
			e[i].cap -= tmp, e[i^1].cap += tmp;
		}
	}
	return g;
}

int main() {
	n = rd(), m = rd(), G = rd();
	for (int _=1;_<=n;_++) g[_] = rd();
	for (int _=1;_<=n;_++) v[_] = rd();
	
	S = ++tot, T = ++tot;
	for (int _=1;_<=n;_++) l[_] = ++tot;
	for (int _=1;_<=n;_++)
		if (g[_] == 0)
			add(S,l[_],0), add(l[_],T,v[_]);
		else
			add(S,l[_],v[_]), add(l[_],T,0);
	
	while (m--) {
		int tmp = ++tot;
		int c = rd(), w = rd(), k = rd();
		for (int _=1;_<=k;_++) {
			int t = rd();
			if (c == 0) add(l[t],tmp,INF); else add(tmp,l[t],INF);
		}
		int fr = rd();
		ans += w;
		if (fr) w += G;
		if (c == 0) add(tmp,T,w); else add(S,tmp,w);
	}
	
	while (BFS()) ans -= DFS(S,INF);
	printf("%d\n",ans);
	return 0;
}