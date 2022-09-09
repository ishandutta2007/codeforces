#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n;
	scanf("%d",&n);
	vector<pii> p(n);
	for(pii &x: p) scanf("%d%d",&x.first,&x.second);
	
	sort(p.begin(), p.end(), [](pii x,pii y){
		return x.second != y.second? x.second < y.second: x.first > y.first;
	});
	
	vector< vector<int> > g(n);
	stack<int> sta;
	for(int i=0; i<n; ++i)
	{
		while(sta.size() && p[sta.top()].first >= p[i].first)
		{
			g[i].push_back(sta.top());
			sta.pop();
		}
		sta.push(i);
		
		sort(g[i].begin(), g[i].end());
		
		printf("%d %d ",p[i].first,p[i].second);
		if(g[i].size() == 0)
			printf("%d\n",p[i].first);
		else
		{
			sort(g[i].begin(), g[i].end());
			if(p[g[i][0]].first == p[i].first)
				printf("%d\n",p[g[i][0]].second + 1);
			else
				printf("%d\n",p[i].first);
		}
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}