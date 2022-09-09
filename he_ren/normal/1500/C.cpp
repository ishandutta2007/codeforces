#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1.5e3 + 5;
const int MAXM = 1.5e3 + 5;

int n,m;
int a[MAXN][MAXM], b[MAXN][MAXM];
vector<int> ans;

inline bool cmp(int x,int y)
{
	for(int j=0; j<(int)ans.size(); ++j)
		if(a[x][ans[j]] != a[y][ans[j]]) return a[x][ans[j]] < a[y][ans[j]];
	return a[x][m+1] < a[y][m+1];
}

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) scanf("%d",&a[i][j]), a[i][m+1] = i;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) scanf("%d",&b[i][j]);
	
	static bool beg[MAXN][MAXM], eq[MAXN][MAXM];
	static int fcnt[MAXM];
	queue<int> q;
	for(int j=1; j<=m; ++j)
	{
		beg[1][j] = eq[1][j] = 1;
		for(int i=2; i<=n; ++i)
		{
			if(b[i][j] < b[i-1][j]) beg[i][j] = 1, ++fcnt[j];
			if(b[i][j] != b[i-1][j]) eq[i][j] = 1;
		}
		if(!fcnt[j]) q.push(j);
	}
	
	static bool has[MAXN];
	has[1] = 1;
	while(q.size())
	{
		int u = q.front(); q.pop();
		ans.push_back(u);
		for(int i=1; i<=n; ++i)
			if(eq[i][u] && !has[i])
			{
				has[i] = 1;
				for(int v=1; v<=m; ++v)
					if(beg[i][v])
					{
						--fcnt[v];
						if(!fcnt[v]) q.push(v);
					}
			}
	}
	
	static int p[MAXN];
	for(int i=1; i<=n; ++i) p[i] = i;
	sort(p+1,p+n+1,cmp);
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			if(a[p[i]][j] != b[i][j])
				return printf("-1"), 0;
	reverse(ans.begin(),ans.end());
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i) printf("%d ",ans[i]);
	return 0;
}