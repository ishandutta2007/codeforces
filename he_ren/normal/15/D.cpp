#include<cstdio>
#include<queue>
typedef long long ll;
const int MAXN = 1e3 + 5;
using namespace std;

int p[MAXN][MAXN],mn[MAXN][MAXN];
ll sum[MAXN][MAXN];

struct Min_que
{
	int a[MAXN],q[MAXN],hd,tl;
	Min_que(){ hd=tl=0;}
	inline void init(void){ hd=tl=0;}
	inline void push(int x)
	{
		while(a[q[tl]]>=a[x] && tl>hd) --tl;
		q[++tl]=x;
	}
	inline void pop(void)
	{
		if(hd<tl) ++hd;
	}
	inline int head(void){ return q[hd+1];}
}q;

struct Mir
{
	int x,y;
	ll mn;
	friend bool operator < (Mir x,Mir y)
	{
		if(x.mn!=y.mn) return x.mn>y.mn;
		if(x.x!=y.x) return x.x>y.x;
		return x.y>y.y;
	}
};

priority_queue<Mir> h;
queue<Mir> ans;

bool vis[MAXN][MAXN];
bool can(int x,int y,int a,int b)
{
	if(vis[x][y] || vis[x+a-1][y+b-1] || vis[x][y+b-1] || vis[x+a-1][y]) return 0;
	
	for(int i=x; i<x+a; ++i)
		for(int j=y; j<y+b; ++j)
			vis[i][j]=1;
	return 1;
}

int main(void)
{
	int n,m,a,b;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) scanf("%d",&p[i][j]);
	
	for(int i=1; i<=n; ++i)
	{
		q.init();
		for(int j=1; j<=m; ++j) q.a[j] = p[i][j];
		
		for(int j=1; j<b; ++j) q.push(j);
		for(int j=1; j<=m; ++j)
		{
			if(q.head()<j) q.pop();
			if(j+b-1<=m) q.push(j+b-1);
			mn[i][j] = p[i][q.head()];
		}
	}
	
	for(int j=1; j<=m; ++j)
	{
		q.init();
		for(int i=1; i<=n; ++i) q.a[i] = mn[i][j];
		
		for(int i=1; i<a; ++i) q.push(i);
		for(int i=1; i<=n; ++i)
		{
			if(q.head()<i) q.pop();
			if(i+a-1<=n) q.push(i+a-1);
			mn[i][j] = min(mn[i][j], mn[q.head()][j]);
		}
	}
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + p[i][j];
	
	for(int i=1; i+a-1<=n; ++i)
	{
		int x=i+a-1;
		for(int j=1; j+b-1<=m; ++j)
		{
			int y=j+b-1;
			//printf("%3lld/%d ",sum[x][y]-sum[i-1][y]-sum[x][j-1]+sum[i-1][j-1],mn[i][j]);
			h.push((Mir){i,j, sum[x][y]-sum[i-1][y]-sum[x][j-1]+sum[i-1][j-1] - (ll)a*b*mn[i][j]});
		}
		//putchar('\n');
	}
	
	int tot=0;
	while(!h.empty() && tot<n*m)
	{
		Mir mr = h.top(); h.pop();
		if(can(mr.x,mr.y,a,b))
			ans.push(mr),
			tot += a*b;
	}
	printf("%d\n",(int)ans.size());
	while(!ans.empty())
	{
		Mir mr = ans.front(); ans.pop();
		printf("%d %d %lld\n",mr.x,mr.y,mr.mn);
	}
	return 0;
}