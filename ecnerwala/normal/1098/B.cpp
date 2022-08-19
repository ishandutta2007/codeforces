#include<bits/stdc++.h>
using namespace std;

vector<string> transpose(int N, int M, const vector<string>& grid) {
	vector<string> res(M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			res[j] += grid[i][j];
		}
	}
	return res;
}

pair<int, vector<string>> solveRows(int N, int M, const vector<string>& grid) {
	pair<int, vector<string>> res;
	res.first = N * M + 1;
	for (int m = 0; m < 16; m++) {
		if (__builtin_popcount(unsigned(m)) != 2) continue;
		int a = 0;
		while (m & (1 << a)) a++;
		int b = a+1;
		while (m & (1 << b)) b++;
		int c = 0;
		while (c == a || c == b) c++;
		int d = c+1;
		while (d == a || d == b) d++;

		int cost = 0;
		vector<string> cnd;
		for (int i = 0; i < N; i++) {
			string s1;
			for (int j = 0; j < M; j++) {
				s1 += "ACTG"[j % 2 ? b : a];
			}
			string s2;
			for (int j = 0; j < M; j++) {
				s2 += "ACTG"[j % 2 ? a : b];
			}

			int c1 = 0, c2 = 0;
			for (int j = 0; j < M; j++) {
				c1 += (s1[j] != grid[i][j]);
				c2 += (s2[j] != grid[i][j]);
			}
			if (c1 > c2) {
				swap(c1, c2);
				swap(s1, s2);
			}
			cnd.push_back(s1);
			cost += c1;

			swap(a,c);
			swap(b,d);
		}

		res = min(res, pair<int, vector<string>>(cost, cnd));
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	vector<string> grid(N);
	for (int i = 0; i < N; i++) {
		cin >> grid[i];
	}

	pair<int, vector<string>> best = solveRows(N, M, grid);
	auto tgrid = transpose(N, M, grid);
	pair<int, vector<string>> tbest = solveRows(M, N, tgrid);
	tbest.second = transpose(M, N, tbest.second);

	best = min(best, tbest);

	//cerr << best.first << '\n';
	for (string s : best.second) {
		cout << s << '\n';
	}

	return 0;
}