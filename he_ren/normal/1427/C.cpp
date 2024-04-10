#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXM = 5e2 + 5;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;

inline int Abs(int x){ return x<0? -x: x;}

struct Node
{
	int t,x,y;
}p[MAXN];

int main(void)
{
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=1; i<=n; ++i)
		scanf("%d%d%d",&p[i].t,&p[i].x,&p[i].y);
	p[0] = (Node){0,1,1};
	
	static int f[MAXN];
	static vector<int> g[MAXN];
	
	for(int i=1; i<=n; ++i) f[i] = -inf;
	
	int ans = 0;
	
	int mx = -inf;
	for(int i=0; i<=n; ++i)
	{
		for(int j=0; j<(int)g[i].size(); ++j)
			mx = max(mx, g[i][j]);
		
		f[i] = max(f[i], mx);
		ans = max(ans, f[i]);
		
		if(f[i] == -inf) continue;
		
		int j = i+1;
		for(; j<=n && p[j].t - p[i].t < m*2; ++j)
		{
			if(Abs(p[j].x - p[i].x) + Abs(p[j].y - p[i].y) <= p[j].t - p[i].t)
				f[j] = max(f[j], f[i]+1);
		}
		
		if(j<=n) g[j].push_back(f[i]+1);
	}
	
	printf("%d",ans);
	return 0;
}