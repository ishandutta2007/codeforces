#include<bits/stdc++.h>
using namespace std;

const int MAXN = 6e5;
int N;
int nxt[MAXN];

void go() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> nxt[i];
	vector<pair<int, int>> edges;
	stack<int> stk;
	stk.push(N+1);
	for (int i = N; i >= 1; i--) {
		if (nxt[i] == -1) {
			nxt[i] = i+1;
		}
		while (stk.top() != nxt[i]) {
			if (stk.top() > nxt[i]) {
				cout << -1 << '\n';
				return;
			} else {
				edges.emplace_back(stk.top(), i);
				stk.pop();
			}
		}
		assert(stk.top() == nxt[i]);
		edges.emplace_back(i, stk.top());
		stk.push(i);
	}
	vector<vector<int>> outEdges(N+2);
	vector<int> inDeg(N+2);
	vector<int> P(N+1);
	for (auto it : edges) {
		outEdges[it.first].push_back(it.second);
		inDeg[it.second] ++;
	}
	stack<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDeg[i] == 0) q.push(i);
	}
	for (int v = 1; v <= N; v++) {
		assert(!q.empty());
		int cur = q.top(); q.pop();
		P[cur] = v;
		for (int b : outEdges[cur]) {
			if (--inDeg[b] == 0) {
				q.push(b);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << P[i] << " \n"[i==N];
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		go();
	}

	return 0;
}