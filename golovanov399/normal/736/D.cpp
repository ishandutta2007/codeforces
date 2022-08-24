#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 2222;
using row = bitset<N + N>;

row matrix[N];

void show(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n + n; ++j) {
			cerr << matrix[i][j];
			if (j == n) {
				cerr << " ";
			}
		}
		cerr << "\n";
	}
	cerr << "\n";
}

int main(){

	int n = nxt(), m = nxt();
	for (int i = 0; i < n; ++i) {
		matrix[i][n + i] = 1;
	}

	vector<pair<int, int>> q;
	for (int i = 0; i < m; ++i) {
		int c = nxt() - 1, r = nxt() - 1;
		matrix[r][c] = 1;
		q.push_back({r, c});
	}

	// show();

	for (int i = 0; i < n; ++i) {
		int j = i;
		while (j < n && !matrix[j][i]) {
			++j;
		}
		if (j != i) {
			matrix[i] ^= matrix[j];
			matrix[j] ^= matrix[i];
			matrix[i] ^= matrix[j];
		}
		for (j = i + 1; j < n; ++j) {
			if (matrix[j][i]) {
				matrix[j] ^= matrix[i];
			}
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i - 1; j >= 0; --j) {
			if (matrix[j][i]) {
				matrix[j] ^= matrix[i];
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		puts(matrix[q[i].second][n + q[i].first] ? "NO" : "YES");
	}

	return 0;
}