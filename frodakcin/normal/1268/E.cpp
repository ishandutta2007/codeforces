#include <cstdio>
#include <algorithm>
 
const int MN = 5e5 + 100;
const int MM = 5e5 + 100;
 
int N, M;
int a[MM], b[MM];
int v[MN], f[MM], k[MM];
 
int hd[MM*2], nx[MM*2], to[MM*2];
bool u[MM];
int X = 2;
void adde(int a, int b)
{
	nx[X] = hd[a];
	hd[a] = X;
	to[X] = b;
	++X;
}
int st[MM], S;
bool vis[MN];
void dfs(int n = 1, int p = 0)
{
	if(vis[n])
	{
		int T, *t, L;
		for(T=S-1;T && to[st[T-1]] != n;--T);
		t = st+T;
		L = S-T;
		int m = 0;
		for(int i = 1;i < L;++i)
			if(t[i] < t[m])
				m = i;
		int u, d;
		for(u = m;t[u+1<L?u+1:u+1-L]>t[u<L?u:u-L];++u);
		for(d = m+L;t[d-1<L?d-1:d-1-L]>t[d<L?d:d-L];--d);
		if(u==d) k[t[m]/2] = t[u<L?u:u-L]/2;
		return;
	}
	vis[n] = 1;
	for(int e = hd[n], x;e;e = nx[e])
	{
		x = to[e];
		if(u[e/2]) continue;
		u[e/2] = 1;
		st[S++] = e;
		dfs(x, n);
		--S;
	}
}
 
int main(void)
{
	scanf("%d%d", &N, &M);
	for(int i = 1;i <= M;++i)
		scanf("%d%d", a+i, b+i), adde(a[i], b[i]), adde(b[i], a[i]);
	for(int i = 1;i <= N;++i)
		v[i] = 1;
	dfs();
	for(int i = M;i > 0;--i)
		v[a[i]] = v[b[i]] = f[i] = v[a[i]] + v[b[i]] - f[k[i]];
	for(int i = 1;i <= N;++i)
		printf("%d%c", v[i]-1, i==N?'\n':' ');
	return 0;
}