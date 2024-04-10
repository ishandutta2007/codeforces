#include<cstdio>
#include<algorithm>
using namespace std;
#define lowbit(x) ((x)&-(x))
typedef long long ll;
const int MAXN = 3e3 + 5;
const int MAXM = 3e3 + 5;

int n,m,mxx;
char s[MAXN][MAXM];
int a[MAXN][MAXM];
int mxl[MAXN][MAXM],mxld[MAXN][MAXM];

struct BIT
{
	int tree[MAXN+MAXM];
	inline void update(int x,int k)
	{
		while(x<=mxx)
			tree[x]+=k,
			x+=lowbit(x);
	}
	inline int query(int x)
	{
		int res=0;
		while(x)
			res+=tree[x],
			x^=lowbit(x);
		return res;
	}
}tree[MAXM];

struct Node
{
	int x,id;
}b[MAXN];
inline bool cmp(const Node &p,const Node &q){ return p.x<q.x;}

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			a[i][j] = (s[i][j]=='z');
	
	for(int i=n; i>=1; --i)
		for(int j=1; j<=m; ++j)
			if(a[i][j])
			{
				mxl[i][j] = mxl[i][j-1]+1;
				mxld[i][j] = mxld[i+1][j-1]+1;
			}
	
	mxx=n+m;
	ll ans=0;
	for(int j=1; j<=m; ++j)
	{
		for(int i=1; i<=n; ++i)
		{
			int len = min(mxl[i][j],mxld[i][j]);
			b[i]=(Node){i+len-1,i};
		}
		sort(b+1,b+n+1,cmp);
		int now=1;
		while(now<=n && !b[now].x) ++now;
		for(int i=1; i<=n && now<=n; ++i)
		{
			tree[j].update(i-mxl[i][j]+m,1);
			while(now<=n && b[now].x==i)
			{
				ans += tree[j].query(b[now].id+m-1)-b[now].id+1;
				++now;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}