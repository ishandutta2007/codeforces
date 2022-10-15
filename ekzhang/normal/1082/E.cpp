#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 500013
int N, C;
int A[MAXN];
int pre[MAXN];
vector<int> by[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		pre[i + 1] = pre[i] + (A[i] == C);
		by[A[i]].push_back(i);
	}

	int best = 0;
	for (int x = 0; x < MAXN; x++) {
		if (by[x].empty() || x == C)
			continue;
		int p = by[x][0];
		int val = 0;
		for (int idx : by[x]) {
			val = max(1, val + 1 - (pre[idx] - pre[p]));
			p = idx;
			best = max(best, val);
		}
	}

	cout << best + pre[N] << endl;
	return 0;
}