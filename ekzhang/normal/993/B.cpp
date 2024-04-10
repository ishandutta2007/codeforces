#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 13
#define MAXM 13

int N, M;
pair<int, int> A[MAXN];
pair<int, int> B[MAXM];
bool possible[10];

int match(pair<int, int> p, pair<int, int> q) {
	if (p == q) return -1;
	if (p.first == q.second) return p.first;
	if (p.first == q.first) return p.first;
	if (p.second == q.first) return p.second;
	if (p.second == q.second) return p.second;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
		if (A[i].first > A[i].second)
			swap(A[i].first, A[i].second);
	}

	for (int i = 0; i < M; i++) {
		cin >> B[i].first >> B[i].second;
		if (B[i].first > B[i].second)
			swap(B[i].first, B[i].second);
	}

	int npossible = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int k = match(A[i], B[j]);
			if (k != -1 && !possible[k]) {
				possible[k] = true;
				npossible++;
			}
		}
	}

	if (npossible == 1) {
		for (int i = 1; i <= 9; i++) {
			if (possible[i]) {
				cout << i << endl;
				return 0;
			}
		}
	}

	else {
		bool ok = true;

		// 0 case; both players know but NOT ME
		for (int i = 0; i < N; i++) {
			// see if player 1 knows
			int npossible = 0;
			memset(possible, 0, sizeof possible);
			for (int j = 0; j < M; j++) {
				int k = match(A[i], B[j]);
				if (k != -1 && !possible[k]) {
					possible[k] = true;
					npossible++;
				}
			}
			if (npossible >= 2)
				ok = false;
		}

		for (int i = 0; i < M; i++) {
			int npossible = 0;
			memset(possible, 0, sizeof possible);
			for (int j = 0; j < N; j++) {
				int k = match(A[j], B[i]);
				if (k != -1 && !possible[k]) {
					possible[k] = true;
					npossible++;
				}
			}
			if (npossible >= 2)
				ok = false;
		}

		cout << (ok ? 0 : -1) << endl;
	}
	return 0;
}