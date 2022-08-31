#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long MOD = ll(1e9) + 7;
// jellyfish are 2x, trees are (N+1)x

const int MAXN = 4e5;
int N;
int adj[MAXN];
int en[MAXN];
bool in_stack[MAXN];
int size[MAXN]; // subtree size

ll res = 1;

// returns terminus
int dfs(int cur) {
	assert(in_stack[cur] == false);
	if (en[cur] != -1) {
		return en[cur];
	}

	int nxt = adj[cur];
	if (nxt == 0) {
		en[cur] = cur;
		return en[cur];
	}

	in_stack[cur] = true;
	if (in_stack[nxt]) {
		if (nxt != cur) {
			res *= 2;
			res %= MOD;
		}
		en[cur] = 0;
	} else {
		en[cur] = dfs(nxt);
	}
	in_stack[cur] = false;
	size[en[cur]] ++;
	return en[cur];
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b; scanf("%d %d", &a, &b);
		assert(1 <= a && a <= 2 * N);
		assert(1 <= b && b <= 2 * N);
		adj[a] = b;
	}
	memset(en, -1, sizeof(en));
	for (int i = 1; i <= 2 * N; i++) {
		dfs(i);
	}
	for (int i = 1; i <= 2 * N; i++) {
		if (size[i]) {
			res *= size[i] + 1;
			res %= MOD;
		}
	}
	cout << res % MOD << '\n';

	return 0;
}