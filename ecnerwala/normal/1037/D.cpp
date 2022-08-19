#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int N;
vector<int> adj[MAXN];
int par[MAXN];
int A[MAXN];

[[noreturn]] void FAIL() {
	cout << "No" << '\n';
	exit(0);
}

int loc[MAXN];
void go() {
	int st = 1; // end of the q
	for (int i = 1; i <= N; i++) {
		int cur = A[i];
		assert(!adj[cur].empty());
		int en = st + int(adj[cur].size()) - 1;
		assert(en <= N);
		for (int nxt : adj[cur]) {
			if (nxt == par[cur]) continue;
			par[nxt] = cur;
			if (st < loc[nxt] && loc[nxt] <= en) {
				// we're good
			} else {
				FAIL();
			}
		}
		st = en;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		assert(1 <= A[i] && A[i] <= N);
		if (loc[A[i]]) FAIL();
		loc[A[i]] = i;
	}
	for (int i = 1; i <= N; i++) {
		assert(1 <= loc[i] && loc[i] <= N);
	}

	if (A[1] != 1) FAIL();

	// might as well, for consistency
	adj[0].push_back(A[1]);
	adj[A[1]].push_back(0);
	par[A[1]] = 0;

	go();

	cout << "Yes" << '\n';
	return 0;
}