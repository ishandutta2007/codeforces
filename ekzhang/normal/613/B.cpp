#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int N;
LL A[MAXN];
LL K, M; // K is max. skill level; M is # credits
int CF, CM;
int order[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K >> CF >> CM >> M;
	for (int i = 0; i < N; i++)
		cin >> A[i], order[i] = i;

	sort(order, order + N, [](int i, int j) { return A[i] > A[j]; });

	int cur = N;
	LL g = 0;
	LL spare = M;
	while (cur > 0) {
		int nc = cur - 1;
		g += A[order[nc]];
		LL amt = ((N - nc) * A[order[nc]] - g);
		if (amt <= M) {
			--cur;
			spare = M - amt;
		}
		else break;
	}

	LL bestans = -1;
	int bestnmaxed;
	LL bestminlevel;

	for (int nmaxed = 0; nmaxed < N; nmaxed++) {
		LL minlevel = A[order[cur]];
		minlevel += spare / (N - cur);
		if (minlevel >= K) {
			bestans = CF * N + CM * K;
			bestnmaxed = N;
			bestminlevel = K;
			break;
		}
		LL ans = CF * nmaxed + CM * minlevel;
		if (ans > bestans) {
			bestans = ans;
			bestnmaxed = nmaxed;
			bestminlevel = minlevel;
		}
		// update to the next value of nmaxed
		LL boost = K - A[order[nmaxed]];
		while (spare < boost || nmaxed == cur) {
			if (cur == N - 1) break;
			int nc = cur + 1;
			spare += (A[order[cur]] - A[order[nc]]) * (N - nc);
			cur = nc;
		}
		if (spare < boost) break;
		spare -= boost;
	}

	for (int i = 0; i < bestnmaxed; i++) {
		A[order[i]] = K;
	}
	for (int i = 0; i < N; i++) {
		A[i] = max(A[i], bestminlevel);
	}

	cout << bestans << endl;
	for (int i = 0; i < N; i++)
		cout << A[i] << ' ';
	cout << endl;
	return 0;
}