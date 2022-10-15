#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int N, M;
vector<vector<int> > A;
vector<vector<int> > B;
set<pair<int, int> > s;
bool good = true;

bool emp(int u, int v) {
	if (s.count({u, v})) return false;
	if (s.count({v, u})) return false;
	return true;
}

void go() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i) {
				s.emplace(A[i][j], A[i-1][j]);
				s.emplace(A[i-1][j], A[i][j]);
			}
			if (j) {
				s.emplace(A[i][j], A[i][j-1]);
				s.emplace(A[i][j-1], A[i][j]);
			}
			if (i < N - 1) {
				s.emplace(A[i][j], A[i+1][j]);
				s.emplace(A[i+1][j], A[i][j]);
			}
			if (j < M - 1) {
				s.emplace(A[i][j], A[i][j+1]);
				s.emplace(A[i][j+1], A[i][j]);
			}
		}
	}
}

bool test() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i) {
				if (!emp(A[i][j], A[i-1][j])) return false;
			}
			if (j) {
				if (!emp(A[i][j], A[i][j-1])) return false;
			}
			if (i < N - 1) {
				if (!emp(A[i][j], A[i+1][j])) return false;
			}
			if (j < M - 1) {
				if (!emp(A[i][j], A[i][j+1])) return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	A = vector<vector<int> >(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[i][j] = M * i + j;
		}
	}

	if (N >= 3 && M >= 3) {
		cout << "YES" << '\n';
		B = vector<vector<int> >(N, vector<int>(M));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				B[i][j] = A[i][(j + i) % M];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				A[i][j] = B[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				B[i][j] = A[(i + j) % N][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << B[i][j] + 1 << ' ';
			}
			cout << '\n';
		}
	}
	else if (N * M <= 9) {
		go();
		vector<int> perm(N * M);
		for (int i = 0; i < N * M; i++) {
			perm[i] = i;
		}
		do {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					A[i][j] = perm[i * M + j];
				}
			}
			if (test()) {
				cout << "YES" << '\n';
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						cout << A[i][j] + 1 << ' ';
					}
					cout << '\n';
				}
				cout.flush();
				return 0;
			}
		} while (next_permutation(perm.begin(), perm.end()));
		cout << "NO" << endl;
	}
	else {
		bool swp = false;
		if (N > M) swap(N, M), swp = true;

		A = vector<vector<int> >(N, vector<int>(M));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				A[i][j] = M * i + j;
			}
		}

		if (N == 1) {
			vector<int> B(M);
			int cur = 1;
			for (int i = 0; i < M; i+= 2) {
				B[i] = cur++;
			}
			for (int i = 1; i < M; i+= 2) {
				B[i] = cur++;
			}
			cout << "YES" << '\n';
			for (int x : B) {
				cout << x << (swp ? '\n' : ' ');
			}
			cout << '\n';
		}
		// N == 2
		else {
			cout << "YES" << '\n';
			B = vector<vector<int> >(N, vector<int>(M));
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					B[i][j] = A[i][(M + j - 2 * i) % M];
				}
			}
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					A[i][j] = B[i][j];
				}
			}
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					B[i][j] = A[(i + j) % N][j];
				}
			}
			if (!swp) {
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						cout << B[i][j] + 1 << ' ';
					}
					cout << '\n';
				}
			}
			else {
				for (int j = 0; j < M; j++) {
					for (int i = 0; i < N; i++) {
						cout << B[i][j] + 1 << ' ';
					}
					cout << '\n';
				}
			}
		}
	}

	cout.flush();
	return 0;
}