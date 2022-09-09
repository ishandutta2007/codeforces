#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const int LB = 20 + 5;

int lb[MAXN];

int a[MAXN];
pii p[MAXM];

int st[MAXN][LB];
inline int st_query(int l,int r)
{
	int lbb = lb[r-l+1];
	return max(st[l][lbb], st[r-(1<<lbb)+1][lbb]);
}

void solve(void)
{	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	int m;
	scanf("%d",&m);
	for(int i=1; i<=m; ++i)
		scanf("%d%d",&p[i].first,&p[i].second);
	
	sort(p+1,p+m+1);
	
	vector<pii> sta;
	for(int i=1; i<=m; ++i)
	{
		while(sta.size() && sta.back().second <= p[i].second)
			sta.pop_back();
		sta.push_back(p[i]);
	}
	
	m = (int)sta.size();
	for(int i=1; i<=m; ++i)
		p[i] = sta[i-1];
	p[m+1] = make_pair(0,0);
	
	static int use[MAXN];
	for(int i=1; i<=n; ++i) use[i] = -1;
	for(int i=1; i<=m; ++i)
		for(int j=p[i].second; j>p[i+1].second; --j)
			use[j] = i;
	
	for(int i=1; i<=n; ++i)
		st[i][0] = a[i];
	for(int i=n; i>=1; --i)
		for(int j=1; i+(1<<j)-1 <= n; ++j)
			st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
	
	for(int i=1; i<=n; ++i)
		if(a[i] > p[m].first){ printf("-1\n"); return;}
	
	int ans = 0, cur = 1;
	while(cur <= n)
	{
		int l = 1, r = min(p[1].second, n-cur+1);
		while(l<r)
		{
			int mid = (l+r+1)>>1;
			if(st_query(cur,cur+mid-1) <= p[use[mid]].first) l = mid;
			else r = mid-1;
		}
		
		++ans;
		cur += l;
	}
	printf("%d\n",ans);
}

int main(void)
{
	for(int i=2; i<MAXN; ++i) lb[i] = lb[i>>1] + 1;
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}