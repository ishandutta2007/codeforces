#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 503
int N, M;
vector<int> A[2 * MAXN];
vector<int> B[2 * MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int x; cin >> x;
			A[i + j].push_back(x);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int x; cin >> x;
			B[i + j].push_back(x);
		}
	}

	bool ok = true;
	for (int i = 0; i < N + M - 1; i++) {
		sort(A[i].begin(), A[i].end());
		sort(B[i].begin(), B[i].end());
		if (!equal(A[i].begin(), A[i].end(), B[i].begin()))
			ok = false;
	}

	cout << (ok ? "YES" : "NO") << endl;
	return 0;
}