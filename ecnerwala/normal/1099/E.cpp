#include<bits/stdc++.h>
using namespace std;

pair<int, string> solveRow(const string& row, char c1, char c2) {
	pair<int, string> s1, s2;
	for (size_t i = 0; i < row.size(); i++) {
		s1.second += c1;
		s1.first += s1.second[i] != row[i];
		s2.second += c2;
		s2.first += s2.second[i] != row[i];
		swap(c1, c2);
	}
	assert(s1.second.size() == row.size());
	assert(s2.second.size() == row.size());
	return min(s1, s2);
}

pair<int, vector<string>> solveRows(const vector<string>& grid) {
	pair<int, vector<string>> res;
	for (int i = 0; i < 4; i++) {
		for (int j = i+1; j < 4; j++) {
			int a = i, b = j;
			int c = 0; while (c == a || c == b) c++;
			int d = c+1; while (d == a || d == b) d++;

			pair<int, vector<string>> cnd;
			for (size_t r = 0; r < grid.size(); r++) {
				auto rowRes = solveRow(grid[r], "ACTG"[a], "ACTG"[b]);
				cnd.first += rowRes.first;
				cnd.second.push_back(rowRes.second);
				swap(a, c);
				swap(b, d);
			}

			if (res.second.empty() || cnd < res) {
				res = std::move(cnd);
			}
		}
	}
	assert(!res.second.empty());
	return res;
}

vector<string> transpose(const vector<string>& grid) {
	vector<string> res;
	for (size_t i = 0; i < grid[0].size(); i++) {
		string row;
		for (size_t j = 0; j < grid.size(); j++) {
			row += grid[j][i];
		}
		res.push_back(row);
	}
	return res;
}

pair<int, vector<string>> solveCols(const vector<string>& grid) {
	auto res = solveRows(transpose(grid));
	res.second = transpose(res.second);
	return res;
}

pair<int, vector<string>> solve(const vector<string>& grid) {
	return min(solveRows(grid), solveCols(grid));
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	size_t N, M;
	cin >> N >> M;
	vector<string> grid(N);
	for (size_t i = 0; i < N; i++) {
		cin >> grid[i];
	}
	auto res = solve(grid);
	cerr << res.first << '\n';
	for (const auto& row : res.second) {
		cout << row << '\n';
	}

	return 0;
}