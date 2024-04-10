#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
#define MAXM 200013
#define MAXG (MAXM+MAXN)
int N, M;
int tnode[MAXM], fnode[MAXM];
bool badv[MAXM], bade[MAXN];
bool ans[MAXM];
int vidx[MAXM];
int eidx[MAXN];
int goal[MAXM];
int A, B;

// hopcroft_karp.cpp
// Eric K. Zhang; Nov. 22, 2017
vector<int> adj[MAXG];
int match[MAXG];
int dist[MAXG];

bool bfs() {
	queue<int> q;
	memset(dist, -1, sizeof dist);
	for (int i = 0; i < A; i++) {
		if (match[i] == -1) {
			q.push(i);
			dist[i] = 0;
		}
	}
	bool reached = false;
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		for (int v : adj[n]) {
			if (match[v] == -1) reached = true;
			else if (dist[match[v]] == -1) {
				dist[match[v]] = dist[n] + 1;
				q.push(match[v]);
			}
		}
	}
	return reached;
}

bool dfs(int n) {
	if (n == -1) return true;
	for (int v : adj[n]) {
		if (match[v] == -1 || dist[match[v]] == dist[n] + 1) {
			if (dfs(match[v])) {
				match[v] = n, match[n] = v;
				return true;
			}
		}
	}
	return false;
}

int hopcroft_karp() {
	memset(match, -1, sizeof match);

	int matching = 0;
	while (bfs()) {
		for (int i = 0; i < A; i++)
			if (match[i] == -1 && dfs(i))
				matching++;
	}
	return matching;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	memset(tnode, -1, sizeof tnode);
	memset(fnode, -1, sizeof fnode);
	for (int i = 0; i < N; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int x; cin >> x;
			if (x > 0) {
				--x;
				if (~tnode[x]) {
					badv[x] = bade[i] = bade[tnode[x]] = true;
					ans[x] = true;
				}
				tnode[x] = i;
			}
			else {
				x = -x;
				--x;
				if (~fnode[x]) {
					badv[x] = bade[i] = bade[fnode[x]] = true;
				}
				fnode[x] = i;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		if (~tnode[i] && !~fnode[i]) {
			badv[i] = bade[tnode[i]] = true;
			ans[i] = true;
		}
		else if (~fnode[i] && !~tnode[i]) {
			badv[i] = bade[fnode[i]] = true;
			ans[i] = false;
		}
		else if (!~fnode[i] && !~tnode[i]) {
			badv[i] = true;
		}
	}

	memset(vidx, -1, sizeof vidx);
	memset(eidx, -1, sizeof eidx);
	int t = 0;
	for (int i = 0; i < M; i++) {
		if (!badv[i]) {
			vidx[i] = t++;
		}
	}
	A = t;
	t = 0;
	for (int i = 0; i < N; i++) {
		if (!bade[i]) {
			eidx[i] = t++;
		}
	}
	B = t;

	for (int i = 0; i < M; i++) {
		if (!badv[i]) {
			if (!bade[tnode[i]]) adj[vidx[i]].push_back(A + eidx[tnode[i]]);
			if (!bade[fnode[i]]) adj[vidx[i]].push_back(A + eidx[fnode[i]]);
			goal[i] = bade[tnode[i]] ? -1 : A + eidx[tnode[i]];
		}
	}

	int x = hopcroft_karp();
	for (int i = 0; i < N; i++) {
		x += bade[i];
	}
	if (x != N) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << '\n';
	for (int i = 0; i < M; i++) {
		if (!badv[i]) {
			ans[i] = match[vidx[i]] == goal[i];
		}
		cout << ans[i];
	}

	cout << endl;
	return 0;
}