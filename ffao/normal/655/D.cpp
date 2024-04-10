#include <bits/stdc++.h>

 
using namespace std;

typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n, k;
vector<pii> battles;
vector<int> adj[110000];
vector<int> radj[110000];
int in_order[110000];
int beats[110000];

void solve() {
	scanf("%d %d", &n, &k);

	REP(i,k) {
		int u,v;
		scanf("%d %d", &u, &v); u--; v--;
		adj[v].push_back(u);
		radj[u].push_back(v);
		battles.push_back({u,v});
	}

	queue<int> q;
	REP(i,n) {beats[i] = 0; if (adj[i].size()==0) q.push(i); }

	int nxt = 0;
	while (!q.empty()) {
		if (q.size() != 1) {
			printf("-1\n");
			return;
		}

		int beater = q.front(); q.pop();
		in_order[beater] = nxt++;
		for (int o : radj[beater]) {
			beats[o]++;
			if (beats[o] == (int)adj[o].size()) q.push(o);
		}
	} 

	if (nxt != n) {
		printf("-1\n");
		return;
	}

	for (int i = k-1; i >= 0; i--) {
		int kk = in_order[battles[i].first], kkk = in_order[battles[i].second];
		if (abs(kk-kkk) == 1) {
			printf("%d\n", i+1);
			break;
		}
	}
}

int main() {
    solve();
}