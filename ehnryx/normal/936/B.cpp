#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const char nl = '\n';

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> adj[n+1], rev[n+1];
	int degree[n+1];

	int a;
	for (int i = 1; i <= n; i++) {
		cin >> degree[i];
		for (int j = 0; j < degree[i]; j++) {
			cin >> a;
			adj[i].push_back(a);
			rev[a].push_back(i);
		}
	}
	int s;
	cin >> s;

	int vis[n+1][2];
	memset(vis, 0, sizeof vis);
	pii par[n+1][2];
	memset(par, -1, sizeof par);

	stack<pii> next;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			next.push(pii(i,0));
			vis[i][0] = true;
		}
	}

	while (!next.empty()) {
		pii cur = next.top();
		next.pop();
		for (int x : rev[cur.first]) {
			if (!vis[x][!cur.second]) {
				next.push(pii(x,!cur.second));
				vis[x][!cur.second] = true;
				par[x][!cur.second] = cur;
			}
		}
	}

	if (vis[s][1]) {
		cout << "Win" << nl;
		for (pii it = pii(s,1); it.first != -1; it = par[it.first][it.second]) {
			cout << it.first << " ";
		}
		cout << nl;
	}
	else {
		int cyc[n+1], anc[n+1];
		memset(cyc, 0, sizeof cyc);
		memset(anc, 0, sizeof anc);

		stack<int> todo;
		todo.push(s);
		cyc[s] = true;
		while (!todo.empty()) {
			int cur = todo.top();
			if (anc[cur]) {
				anc[cur] = false;
				todo.pop();
				continue;
			}
			anc[cur] = true;
			for (int x : adj[cur]) {
				if (anc[x]) {
					cout << "Draw" << nl;
					return 0;
				}
				else if (!cyc[x]) {
					todo.push(x);
					cyc[x] = true;
				}
			}
		}
		cout << "Lose" << nl;
	}

	return 0;
}