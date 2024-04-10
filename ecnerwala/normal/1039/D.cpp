#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1.1e5;
int N;
vector<int> adj[MAXN];
// flatten it into a reverse BFS traversal
int st[MAXN];

pair<int, int> q[MAXN];
void precomp() {
	int S = 0;
	q[S++] = {1, 0};
	for (int ind = 0; ind < N; ind++) {
		st[ind] = S-1;
		int cur = q[ind].first, prv = q[ind].second;
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			q[S++] = {nxt, cur};
		}
	}
	assert(S == N);
	st[N] = N-1;
}

int dp[MAXN];

int query(int K) {
	int res = 0;
	for (int i = N-1; i >= 0; i--) {
		int m1 = 0, m2 = 0;
		for (int j = st[i+1]; j > st[i]; j--) {
			int cnd = dp[j];
			if (cnd > m2) {
				m2 = cnd;
				if (m2 > m1) {
					swap(m1, m2);
				}
			}
		}

		if (m1 + m2 + 1 >= K) {
			res ++;
			dp[i] = 0;
		} else {
			dp[i] = m1 + 1;
		}
	}

	return res;
}

int res[MAXN];

// exclusive range, with left and right already solved
void solve(int mi, int ma) {
	assert(ma > mi);
	if (ma - mi == 1) return;
	if (res[mi] == res[ma]) {
		for (int i = mi+1; i < ma; i++) {
			res[i] = res[mi];
		}
		return;
	}
	int md = (mi + ma) / 2;
	assert(mi < md && md < ma);
	res[md] = query(md);
	solve(mi, md);
	solve(md, ma);
}

int main() {
	(void) scanf("%d", &N);
	for (int i = 0; i < N-1; i++) {
		int u,v; (void) scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	precomp();

	res[0] = N;
	res[N+1] = 0;
	int l = 0;
	for (l = 1; l * l <= N; l++) {
		res[l] = query(l);
	}
	solve(l-1, N+1);

	ostringstream ans;
	for (int i = 1; i <= N; i++) {
		ans << res[i] << '\n';
	}
	puts(ans.str().c_str());
	return 0;
}