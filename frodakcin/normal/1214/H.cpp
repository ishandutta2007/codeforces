#include <cstdio>
#include <vector>

const int MN = 2e5 + 100;
int N, K;
std::vector<int> a[MN];

int p[MN], d[MN], D;
int q[MN], f[MN];
int get_far(int n = 1)
{
	p[n] = -1, d[n] = 1;
	int r;
	for(int i = 0, j = 0;i <= j;r=n,n=q[++i])
		for(int x : a[n])
			if(p[n]!=x)
				p[x]=n, d[x]=d[n]+1, q[++j] = x;
	return r;
}

int dfs(int n, int p, int d, int v, int z = 1)
{
	d+=v;
	if(d>=K) d -= K;
	f[n] = d;
	int r = z;
	for(int x : a[n])
		if(x != p)
			r = std::max(r, dfs(x, n, d, v, z+1));
	return r;
}

void edge(int n = 1, int p = 0, int d = 0)
{
	f[n] = d;
	for(int x : a[n])
		if(x!=p)
			edge(x, n, d^1);
}

int main(void)
{
	scanf("%d%d", &N, &K);
	for(int i = 0, u, v;i < N-1;i++)
		scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
	if(K>2)
	{
		int t = get_far(get_far());
		for(int i = 1;i <= N;i++) q[i] = 0;
		D = d[t];
		for(int i = 0;~t;t=p[t],++i) d[i] = t, q[t] = 1; 
		for(int i = 0, n;i < D;i++)
		{
			f[d[i]] = i%K;
			int u = std::min(i+1, D-i);
			int v = i+1<D-i?K-1:1;
			for(int x : a[d[i]])
				if(!q[x])
				{
					int d = dfs(x, ::d[i], i%K, v);
					if(u+d>=K) return printf("No\n"), 0;
				}
		}
	}
	else
		edge();
	printf("Yes\n");
	for(int i = 1;i <= N;i++)
		printf("%d%c", f[i]+1, " \n"[i==N]);
	return 0;
}