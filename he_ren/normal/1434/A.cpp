#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXM = 6 + 5;
const int inf = 0x3f3f3f3f;

int m,n;
int a[MAXM], b[MAXN];

void solve(void)
{
	m = 6;
	for(int i=1; i<=m; ++i) scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	sort(b+1,b+n+1);
	
	vector<pair<int,pii> > p;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			p.push_back(make_pair(b[i] - a[j], make_pair(i,j)));
	
	sort(p.begin(),p.end());
	int mx = b[n] - a[m];
	
	int ans = inf;
	for(int i=0; i<(int)p.size(); ++i)
	{
		ans = min(ans, mx - p[i].first);
		
		if(p[i].second.second == 1) break;
		mx = max(mx, b[p[i].second.first] - a[p[i].second.second - 1]);
	}
	
	printf("%d",ans);
}

int main(void)
{
	int T = 1;
	while(T--) solve();
	return 0;
}