#include<cstdio>
const int MAXN = 2e5 + 5;
typedef long long ll;

struct Edge
{
	int next,to,w;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v,int w)
{
	++etot;
	e[etot].next=head[u];
	e[etot].to=v;
	e[etot].w=w;
	head[u]=etot;
}

int n;
bool is[MAXN];

int c[MAXN*2],w[MAXN*2],ccnt=0;
bool vis[MAXN];
int st[MAXN],tp=0;
inline int top(void){ return st[tp];}
inline void push(int x){ st[++tp]=x;}
inline void pop(void){ --tp;}
bool find_c(int u,int last)
{
	vis[u]=1;
	push(u);
	for(int i=head[u]; i; i=e[i].next)
		if(e[i].to!=last)
		{
			if(vis[e[i].to])
			{
				while(top()!=e[i].to)
				{
					is[top()]=1;
					c[++ccnt]=top();
					pop();
				}
				is[e[i].to]=1;
				c[++ccnt]=e[i].to;
				return 1;
			}
			if(find_c(e[i].to,u)) return 1;
		}
	vis[u]=0;
	pop();
	return 0;
}

ll ans[MAXN*2];

int size[MAXN*2];
void dfs(int u,int fa)
{
	size[u]=1;
	for(int i=head[u]; i; i=e[i].next)
		if(e[i].to!=fa && !is[e[i].to])
		{
			int v=e[i].to;
			dfs(v,u);
			ans[u] += ans[v] + e[i].w*size[v];
			size[u]+=size[v];
		}
}

void dfs2(int u,int fa)
{
	for(int i=head[u]; i; i=e[i].next)
		if(e[i].to!=fa && !is[e[i].to])
		{
			int v=e[i].to;
			ans[v] = ans[u] + e[i].w*(n-size[v]) - e[i].w*size[v];
			dfs2(v,u);
		}
}

ll sums[MAXN*2],sumw[MAXN*2],sum[MAXN*2];
int main(void)
{
	scanf("%d",&n);
	for(int i=0; i<n; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	
	find_c(1,0);
	for(int i=1; i<=n ;++i)
		if(is[i]) dfs(i,0);
	
	ll tot=0;
	for(int i=1; i<=ccnt; ++i)
	{
		c[ccnt+i]=c[i];
		tot+=ans[c[i]];
		for(int j=head[c[i]]; j; j=e[j].next)
			if(e[j].to == c[i+1])
			{
				w[ccnt+i]=w[i]=e[j].w;
				break;
			}
	}
	for(int i=1; i<=ccnt*2; ++i)
	{
		sums[i] = sums[i-1]+size[c[i]];
		sumw[i] = sumw[i-1]+w[i];
		sum[i] = sum[i-1] + w[i]*sums[i];
	}
	
	for(int l=1,r=1; l<=ccnt; ++l)
	{
		while(sumw[r]-sumw[l-1] <= (sumw[ccnt]>>1)) ++r;
		ans[c[l]]
		= tot
		+ sums[r]*(sumw[r-1]-sumw[l-1]) - (sum[r-1]-sum[l-1])
		+ (sum[l+ccnt-1]-sum[r]) - sums[r]*(sumw[l+ccnt-1]-sumw[r]);
		dfs2(c[l],0);
	}
	for(int i=1; i<=n; ++i) printf("%lld ",ans[i]);
	return 0;
}