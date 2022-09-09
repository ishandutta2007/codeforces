#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static vector<int> pos[MAXN];
	for(int i=1; i<=n; ++i)
		pos[i].clear(), pos[i].push_back(0);
	
	for(int i=1; i<=n; ++i) pos[a[i]].push_back(i);
	for(int i=1; i<=n; ++i) pos[i].push_back(n+1);
	
	static vector<int> g[MAXN];
	for(int i=1; i<=n; ++i) g[i].clear();
	
	for(int k=1; k<=n; ++k)
	{
		vector<int> &vec = pos[k];
		if(vec.size() <= 2) continue;
		
		int mx = 0;
		for(int i=1; i<(int)vec.size(); ++i)
			mx = max(mx, vec[i] - vec[i-1]);
		
		g[mx].push_back(k);
	}
	
	int ans = n+1;
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<(int)g[i].size(); ++j)
			ans = min(ans, g[i][j]);
		if(ans > n) printf("-1 ");
		else printf("%d ",ans);
	}
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}