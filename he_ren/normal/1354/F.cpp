#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 75 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

inline void chk_max(ll &a,ll b){ if(a<b) a=b;}

struct Node
{
	int a,b,id;
}p[MAXN];
inline bool cmp(const Node &p,const Node &q){ return p.b<q.b;}

ll f[MAXN][MAXN][3];
int g[MAXN][MAXN][3];

int b[MAXN];
vector<int> ans;

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&p[i].a,&p[i].b),
		p[i].id=i;
	
	sort(p+1,p+n+1,cmp);
	
	for(int i=0; i<=n; ++i)
		for(int j=0; j<=d; ++j)
			f[i][j][0] = f[i][j][1] =  -linf;
	
	f[0][0][0] = 0;
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<=d-1; ++j)
		{
			f[i][j][0] = f[i-1][j][0];
			f[i][j][1] = f[i-1][j][1];
			g[i][j][0] = g[i][j][1] = 0;
		}
		
		for(int j=1; j<=d-1; ++j)
		{
			int w = -(d-1-j+1) * p[i].b + p[i].a;
			
			if(f[i][j][0] < f[i-1][j-1][0] + w)
			{
				f[i][j][0] = f[i-1][j-1][0] + w;
				g[i][j][0] = 1;
			}
			if(f[i][j][1] < f[i-1][j-1][1] + w)
			{
				f[i][j][1] = f[i-1][j-1][1] + w;
				g[i][j][1] = 1;
			}
		}
		
		for(int j=0; j<=d-1; ++j)
		{
			if(f[i][j][1] < f[i-1][j][0] + p[i].a)
			{
				f[i][j][1] = f[i-1][j][0] + p[i].a;
				g[i][j][1] = 2;
			}
		}
	}
	
	int x=d-1, y=1;
	for(int i=n; i>=1; --i)
	{
		b[i] = g[i][x][y];
		if(!b[i]) continue;
		if(b[i]==1) --x;
		else --y;
	}
	
	ans.clear();
	for(int i=1; i<=n; ++i)
	{
		if(b[i]==1)
			ans.push_back(p[i].id);
	}
	for(int i=1; i<=n; ++i)
	{
		if(b[i]==0)
			ans.push_back(p[i].id),
			ans.push_back(-p[i].id);
	}
	for(int i=1; i<=n; ++i)
	{
		if(b[i]==2)
			ans.push_back(p[i].id);
	}
	
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d ",ans[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}