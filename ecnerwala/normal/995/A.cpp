#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2000;
int N;
int K;
int A[MAXN]; // spots
int C[MAXN]; // cars

pair<int, int> Aloc(int i) {
	if (i >= N / 2) {
		return pair<int, int>(4, N - i);
	} else {
		return pair<int, int>(1, i + 1);
	}
}

pair<int, int> Cloc(int i) {
	if (i >= N / 2) {
		return pair<int, int>(3, N - i);
	} else {
		return pair<int, int>(2, i + 1);
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> C[2 * N - 1 - i];
	}
	for (int i = 0; i < N; i++) {
		cin >> A[2 * N - 1 - i];
	}

	N *= 2;

	vector<pair<int, pair<int, int>>> res;

	for (int t = 0; K; t++) {
		for (int i = 0; i < N; i++) {
			if (C[i] != 0 && C[i] == A[i]) {
				// move it immediately
				K--;
				res.emplace_back(C[i], Aloc(i));
				C[i] = 0;
				A[i] = 0;
			}
		}
		if (K == 0) break;
		int st = -1;
		for (int i = 0; i < N; i++) {
			if (C[i] == 0) {
				st = i;
				break;
			}
		}
		if (st == -1) {
			cout << -1 << '\n';
			return 0;
		}
		assert(st >= 0);

		for (int i = (st + 1) % N; i != st; i++, i %= N) {
			int p = (i + N-1) % N;
			assert(C[p] == 0);
			if (C[i] == 0) {
				continue;
			}
			res.emplace_back(C[i], Cloc(p));
			C[p] = C[i];
			C[i] = 0;
		}
		/*
		for (int i = 0; i < N; i++) {
			cerr << C[i] << ' ';
		}
		cerr << '\n';
		for (int i = 0; i < N; i++) {
			cerr << A[i] << ' ';
		}
		cerr << '\n';
		cerr << '\n';
		*/
	}

	cout << res.size() << '\n';
	for (const auto &it : res) {
		cout << it.first << ' ' << it.second.first << ' ' << it.second.second << '\n';
	}

	return 0;
}