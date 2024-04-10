#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;

int a[MAXN], b[MAXN], c[MAXM];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	for(int i=1; i<=m; ++i) scanf("%d",&c[i]);
	
	static vector<int> need[MAXN], have[MAXN];
	for(int i=1; i<=n; ++i) need[i].clear(), have[i].clear();
	
	for(int i=1; i<=n; ++i)
	{
		if(a[i] == b[i]) have[b[i]].push_back(i);
		else need[b[i]].push_back(i);
	}
	
	static int res[MAXN];
	
	int ready = 0;
	for(int i=m; i>=1; --i)
	{
		if(need[c[i]].size())
		{
			res[i] = need[c[i]].back();
			have[c[i]].push_back(res[i]); need[c[i]].pop_back();
			ready = res[i];
		}
		else if(have[c[i]].size()) res[i] = ready = have[c[i]].back();
		else if(ready) res[i] = ready;
		else { printf("NO\n"); return;}
	}
	
	for(int i=1; i<=n; ++i)
		if(need[i].size()){ printf("NO\n"); return;}
	printf("YES\n");
	for(int i=1; i<=m; ++i)
		printf("%d ",res[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}