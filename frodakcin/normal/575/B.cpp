#include <cstdio>
#include <vector>

using ll = long long;
const int MN = 1e5+10, MOD = 1e9+7, MK = 1e6+10;
int N, p[MN][20], cnt[MN], l[MN], K, ans[MK];
struct edge{public:int n,w;};
std::vector<edge> a[MN];
ll f;

void dfs(int n)
{
	for(int i=0;p[n][i]&&p[p[n][i]][i];++i)
		p[n][i+1]=p[p[n][i]][i];
	for(auto x:a[n])
	{
		if(x.n==p[n][0]) continue;
		p[x.n][0]=n;
		l[x.n]=l[n]+1;
		dfs(x.n);
	}
}
int mu(int n, int d)
{
	for(int i=0;d;d>>=1,++i)
		if(d&1)
			n=p[n][i];
	return n;
}
int lca(int a, int b)
{
	if(l[b]<l[a]) std::swap(a,b);
	b=mu(b,l[b]-l[a]);
	if(a==b) return a;
	for(int i=16;i>=0;--i)
		if(p[a][i]!=p[b][i])
			a=p[a][i], b=p[b][i];
	return p[a][0];
}

int dfs2(int n=1)
{
	int v=cnt[n];
	for(auto x:a[n])
	{
		if(x.n==p[n][0]) continue;
		int q=dfs2(x.n);
		//printf("%d\n", q);
		if(x.w==1) f+=ans[q>>1];
		if(x.w==2) f+=ans[q+1>>1];
		v+=q;
	}
	return v;
}
int main()
{
	scanf("%d",&N);
	for(int i=0,x,y,z;i+1<N;++i)
	{
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back({y,z});
		a[y].push_back({x,z*2});
	}
	dfs(1);
	scanf("%d", &K);

	int cur = 1;
	for(int i=0;i<=K;++i)
	{
		ans[i]=cur-1;
		cur = cur*2;
		if(cur>=MOD) cur -= MOD;
	}

	int p=1;
	for(int i=0,n,x;i<K;++i)
	{
		scanf("%d",&n);
		x=lca(n,p);
		++cnt[n], ++cnt[p], --cnt[x], --cnt[x];
		p=n;
	}
	dfs2();
	printf("%d\n", f%MOD);
	return 0;
}