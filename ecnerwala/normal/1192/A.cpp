#include<bits/stdc++.h>
using namespace std;

const int mx[8] = {
	1, 1, 0, -1, -1, -1, 0, 1
};
const int my[8] = {
	0, 1, 1, 1, 0, -1, -1, -1
};

const int MAXN = 1.6e5;
int N, T;
pair<int, int> P[MAXN];
int ind[MAXN];

const int MAXV = MAXN * 9;
int V;
pair<int, int> pts[MAXV];
struct {
	bool reachable = false;
	bool visible = false;
	bool inQueue = false;
	bool removed = false;
	int adj[8];
	int id;
} verts[MAXV];
int par[MAXV];
void reset() {
	memset(par, -1, sizeof(par));
}
int getpar(int a) {
	return par[a] == -1 ? a : (par[a] = getpar(par[a]));
}
bool merge(int a, int b) {
	a = getpar(a), b = getpar(b);
	if (a == b) return false;
	par[a] = b;
	return true;
}

bool isPossible() {
	stack<int> q;
	verts[ind[0]].reachable = true;
	q.push(ind[0]);
	int cnt = 0;
	while (!q.empty()) {
		int cur = q.top(); q.pop();
		//cerr << "reach " << cur << '\n';
		cnt++;
		for (int d = 0; d < 8; d++) {
			int nxt = verts[cur].adj[d];
			assert(nxt != -1);
			if (verts[nxt].id == -1) continue;
			//cerr << nxt << '\n';
			if (verts[nxt].reachable) continue;
			verts[nxt].reachable = true;
			q.push(nxt);
		}
	}
	return cnt == N;
}

priority_queue<int> q;

void flood(int cur) {
	if (cur == -1) return;
	if (verts[cur].visible) {
		return;
	}
	verts[cur].visible = true;

	if (verts[cur].id != -1) {
		if (!verts[cur].inQueue) {
			verts[cur].inQueue = true;
			q.push(verts[cur].id);
		}
		return;
	}

	// evens only
	for (int d = 0; d < 8; d += 2) {
		flood(verts[cur].adj[d]);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> P[i].first >> P[i].second;
	}

	V = 0;
	for (int i = 0; i < N; i++) {
		pts[V++] = P[i];
		for (int d = 0; d < 8; d++) {
			pts[V++] = {P[i].first + mx[d], P[i].second + my[d]};
		}
	}
	sort(pts, pts + V);
	V = int(unique(pts, pts + V) - pts);

	for (int v = 0; v < V; v++) { verts[v].id = -1; }
	for (int i = 0; i < N; i++) {
		ind[i] = int(lower_bound(pts, pts + V, P[i]) - pts);
		verts[ind[i]].id = i;
	}

	for (int v = 0; v < V; v++) {
		memset(verts[v].adj, -1, sizeof(verts[v].adj));
	}
	for (int d = 0; d < 8; d++) {
		for (int v = 0, u = 0; v < V && u < V; ) {
			pair<int, int> cnd(pts[v].first + mx[d], pts[v].second + my[d]);
			if (cnd == pts[u]) {
				verts[v].adj[d] = u;
				v++, u++;
			} else if (cnd < pts[u]) {
				v++;
			} else {
				u++;
			}
		}
	}

	/*
	for (int v = 0; v < V; v++) {
		cerr << v << ": " << "(" << pts[v].first << ", " << pts[v].second << ")" << ' ';
		cerr << verts[v].id << " ";
		cerr << "["; for (int d = 0; d < 8; d++) { cerr << verts[v].adj[d] << ", "; } cerr << "]" << '\n';
	}
	*/

	if (isPossible()) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
		exit(0);
	}

	reset();
	for (int v = 0; v < V; v++) {
		if (verts[v].id != -1) continue;
		for (int d = 0; d < 8; d += 2) {
			int u = verts[v].adj[d];
			if (u == -1) continue;
			if (verts[u].id != -1) continue;
			merge(u, v);
		}
	}

	flood(0);

	auto doesntSplit = [] (int cur) {
		assert(verts[cur].id != -1);
		int numClosed = 0;
		for (int d = 0; d < 8; d++) {
			numClosed += (verts[verts[cur].adj[d]].id != -1);
		}

		for (int a = 0; a < 8; a += 2) {
			if (verts[verts[cur].adj[a]].id != -1) continue;
			for (int b = a + 2; b < 8; b += 2) {
				if (verts[verts[cur].adj[b]].id != -1) continue;
				if (getpar(verts[cur].adj[a]) != getpar(verts[cur].adj[b])) continue;
				int midClosed = 0;
				for (int c = a+1; c < b; c++) {
					midClosed += (verts[verts[cur].adj[c]].id != -1);
				}
				if (midClosed == 0 || midClosed == numClosed) {
					// it's fine
				} else {
					return false;
				}
			}
		}
		return true;
	};

	vector<int> ans;
	while (!q.empty()) {
		int cur = ind[q.top()]; q.pop();
		//cerr << cur << '\n';
		verts[cur].inQueue = false;
		if (!doesntSplit(cur)) {
			continue;
		}

		ans.push_back(verts[cur].id);
		verts[cur].id = -1;
		for (int d = 0; d < 8; d += 2) {
			int nxt = verts[cur].adj[d];
			if (verts[nxt].id != -1) continue;
			merge(cur, nxt);
		}

		verts[cur].visible = false;
		flood(cur);
		for (int d = 0; d < 8; d++) {
			int nxt = verts[cur].adj[d];
			if (verts[nxt].id != -1 && verts[nxt].visible && !verts[nxt].inQueue) {
				verts[nxt].inQueue = true;
				q.push(verts[nxt].id);
			}
		}
	}

	reverse(ans.begin(), ans.end());
	for (int i : ans) { cout << i+1 << '\n'; }

	return 0;
}