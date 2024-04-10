#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int n,x,y;
int a[MAXN], ans[MAXN];

vector<int> clr[MAXN];

void solve_eq(void)
{
	static priority_queue<pii> q;
	while(!q.empty()) q.pop();
	
	for(int i=1; i<=n+1; ++i)
		q.push(make_pair((int)clr[i].size(), i));
	for(int i=1; i<=x; ++i)
	{
		pii now = q.top(); q.pop();
		int u = now.second;
		
		ans[clr[u].back()] = a[clr[u].back()];
		clr[u].pop_back();
		
		q.push(make_pair((int)clr[u].size(), u));
	}
}

void solve(void)
{
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) ans[i] = 0;
	
	for(int i=1; i<=n+1; ++i) clr[i].clear();
	for(int i=1; i<=n; ++i)
		clr[a[i]].push_back(i);
	
	int non = 0;
	for(int i=1; i<=n+1; ++i)
		if(clr[i].empty()) non = i;
	
	solve_eq();
	
	static vector<int> rem;
	rem.clear();
	for(int i=1; i<=n+1; ++i)
		for(int j=0; j<(int)clr[i].size(); ++j)
			rem.push_back(clr[i][j]);
	
	rotate(rem.begin(), rem.begin() + (n-x)/2, rem.end());
	reverse(rem.begin(), rem.end());
	
	int cnt = 0;
	for(int i=1; i<=n+1; ++i)
		for(int j=0; j<(int)clr[i].size(); ++j)
		{
			int now = rem.back(); rem.pop_back();
			
			ans[now] = i;
			if(a[now] == i)
				++cnt, ans[now] = non;
		}
	
	if(cnt > n-y)
	{
		printf("No\n");
		return;
	}
	for(int i=1; i<=n+1 && cnt<n-y; ++i)
		if(ans[i] != non && ans[i] != a[i])
			++cnt, ans[i] = non;
	
	printf("Yes\n");
	for(int i=1; i<=n; ++i) printf("%d ",ans[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}