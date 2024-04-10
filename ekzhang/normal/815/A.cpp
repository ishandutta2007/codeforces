#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 113
int N, M;
int A[MAXN][MAXN];
// vector<int> rows[2];
// vector<int> cols[2];
// int t = 0;
vector<pair<string, int> > ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	// int ct = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
			// ct += A[i][j];
		}
	}

	// will only run once
	while (true) {
		int amt = 500;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				amt = min(amt, A[i][j]);
			}
		}
		if (!amt) break;
		// error(amt);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				A[i][j] -= amt;
			}
		}
		for (int t = 0; t < amt; t++) {
			if (N < M) {
				for (int i = 0; i < N; i++) {
					ans.push_back({ "row", i + 1 });
				}
			}
			else {
				for (int i = 0; i < M; i++) {
					ans.push_back({ "col", i + 1 });
				}
			}
		}
	}

	// may run many times
	while (true) {
		int mi = -1, mj = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if ((mi == -1 || A[i][j] < A[mi][mj]) && A[i][j]) {
					mi = i;
					mj = j;
				}
			}
		}
		// error(mi, mj);
		if (mi == -1) break;
		int frow = 500, fcol = 500;
		for (int j = 0; j < M; j++) {
			frow = min(frow, A[mi][j]);
		}
		for (int i = 0; i < N; i++) {
			fcol = min(fcol, A[i][mj]);
		}
		if (((bool) frow) ^ ((bool) fcol)) {
			for (int t = 0; t < max(frow, fcol); t++) {
				if (frow) {
					ans.push_back({ "row", mi + 1 });
				}
				else {
					ans.push_back({ "col", mj + 1 });
				}
			}
			if (frow) {
				for (int j = 0; j < M; j++) {
					A[mi][j] -= frow;
				}
			}
			else {
				for (int i = 0; i < N; i++) {
					A[i][mj] -= fcol;
				}
			}
		}
		else {
			cout << -1 << endl;
			return 0;
		}
	}

	// for (int i = 0; i < N; i++) {
	// 	rows[t].push_back(i);
	// }
	// for (int j = 0; j < M; j++) {
	// 	cols[t].push_back(j);
	// }

	// while (ct) {
	// 	for (int i : rows[t]) {
	// 		bool filled = true;
	// 		for (int j = 0; j < M; j++) {
	// 			if (!A[i][j]) filled = false;
	// 		}
	// 		if (filled) {
	// 			rows[!t].push_back(i);
	// 		}
	// 	}
	// 	for (int j : cols[t]) {
	// 		bool filled = true;
	// 		for (int i = 0; i < N; i++) {
	// 			if (!A[i][j]) filled = false;
	// 		}
	// 		if (filled) {
	// 			cols[!t].push_back(j);
	// 		}
	// 	}
	// 	rows[t].clear();
	// 	cols[t].clear();
	// 	t ^= 1;

	// 	if (rows[t].empty() && cols[t].empty()) {
	// 		cout << -1 << endl;
	// 		return 0;
	// 	}

	// 	int amt = 500;
	// 	for (int i : rows[t]) {
	// 		for (int j : cols[t]) {
	// 			amt = min(amt, A[i][j]);
	// 		}
	// 	}

	// 	for (int i : rows[t]) {
	// 		for (int j : cols[t]) {
	// 			A[i][j] -= amt;
	// 		}
	// 	}

	// 	if (rows[t].size() < cols[t].size()) {
	// 		for (int i : rows[t]) {
	// 			ans.push_back({ "row", i + 1 });
	// 		}
	// 	}
	// 	else {
	// 		for (int i : cols[t]) {
	// 			ans.push_back({ "col", i + 1 });
	// 		}
	// 	}
	// }

	cout << ans.size() << '\n';
	for (auto p : ans) {
		cout << p.first << ' ' << p.second << '\n';
	}

	cout.flush();
	return 0;
}