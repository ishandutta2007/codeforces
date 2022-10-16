#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int n,m,k;
vector<int> adj[310000];
vector<int> rem;
vector< vector<int> > comps;

void solve() {
	scanf("%d %d %d", &n, &m, &k);
	REP(i,m) {
		int u,v;
		scanf("%d %d", &u, &v); u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	REP(i,n) sort(adj[i].begin(), adj[i].end());

	for (int i = 1; i < n; i++) rem.push_back(i);

	while (!rem.empty()) {
		vector<int> tc;
		tc.push_back(rem[0]);
		swap(rem[0], rem[rem.size()-1]);
		rem.pop_back();

		for (int i = 0; i < (int)tc.size(); i++) {
			int curv = tc[i];
			for (int j = 0; j < (int)rem.size(); j++) {
				auto it = lower_bound(adj[curv].begin(), adj[curv].end(), rem[j]);
				if (it == adj[curv].end() || *it != rem[j]) {
					tc.push_back(rem[j]);
					swap(rem[j], rem[rem.size()-1]);
					rem.pop_back();
					j--;
				}
			}
		}
		comps.push_back(tc);
	}

	int rem1 = (n-1) - (int)adj[0].size();
	//printf("rem1 is %d and cs is %d\n", rem1, comps.size());
	if ((int)comps.size() > k || rem1 < k ) {
		printf("impossible\n");
		return;
	}

	REP(i, comps.size()) {
		bool ok = false;
		for (int k : comps[i]) {
			//printf("comps[%d] contains %d\n", i,k);
			if (adj[k].empty() || adj[k][0] != 0) {
				ok = true;
				break;
			}
		}
		if (!ok) {
			printf("impossible\n");
			return;
		}
	}

	printf("possible\n");
}

int main() {
    solve();
}