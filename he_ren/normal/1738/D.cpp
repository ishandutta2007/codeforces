#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int b[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&b[i]);
	
	int d = 0;
	while(d+1 <= n && b[d+1] > d+1) ++d;
	
	static vector<int> pos[MAXN];
	for(int i=0; i<=n+1; ++i)
		pos[i].clear();
	for(int i=1; i<=n; ++i)
		pos[b[i]].push_back(i);
	
	vector<int> ans;
	int u = pos[0].size()? 0: n+1;
	while(pos[u].size())
	{
		int v = pos[u][0];
		for(int t: pos[u])
			if(pos[t].size()) v = t;
		
		for(int t: pos[u])
			if(t != v) ans.push_back(t);
		ans.push_back(v);
		u = v;
	}
	
	printf("%d\n",d);
	for(int t: ans)
		printf("%d ",t);
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}