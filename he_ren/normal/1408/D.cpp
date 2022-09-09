#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e3 + 5;
const int MAXM = 2e3 + 5;
const int MAXX = 1e6 + 5;
const int inf = 0x3f3f3f3f;

struct Node
{
	int x,y;
}p[MAXN], q[MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d%d",&p[i].x,&p[i].y);
	for(int i=1; i<=m; ++i) scanf("%d%d",&q[i].x,&q[i].y);
	
	vector<pii> g;
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			int dx = max(q[j].x - p[i].x + 1, 0);
			int dy = max(q[j].y - p[i].y + 1, 0);
			
			g.push_back(make_pair(dx, dy));
		}
	sort(g.begin(), g.end());
	
	vector<int> mx(g.size() + 1);
	
	for(int i=(int)g.size()-1; i>=0; --i)
		mx[i] = max(mx[i+1], g[i].second);
	
	int ans = mx[0];
	
	for(int i=0; i<(int)g.size(); ++i)
		if(i == (int)g.size()-1 || g[i].first != g[i+1].first)
			ans = min(ans, g[i].first + mx[i+1]);
	
	printf("%d",ans);
	return 0;
}