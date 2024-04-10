#include <bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int, int> > > E;
int dp[300005], maxw[300005];
int oldDp[300005];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i < m; ++i){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		E.push_back(make_pair(w, make_pair(u, v)));
	}
	sort(E.begin(), E.end());
	int ans=0;
	for(int i=0; i < E.size(); ++i){
		int u, v, w;
		w=E[i].first;
		u=E[i].second.first;
		v=E[i].second.second;
		int val;
		if(w == maxw[u])
			val = oldDp[u]+1;
		else
			val = dp[u]+1;
		if(val > dp[v]){
			if(maxw[v] != w)
				oldDp[v]=dp[v];
			dp[v] = val;
			maxw[v]=w;
			ans=max(ans, val);
		}
	}
	printf("%d\n", ans);
}