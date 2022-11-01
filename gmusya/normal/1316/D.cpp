#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <queue>

using namespace std;

vector <int> dsu;

int get(int v) {
	if (v == dsu[v])
		return v;
	return dsu[v] = get(dsu[v]);
}

void uni(int v, int u) {
	v = get(v);
	u = get(u);
	if (u != v) {
		dsu[u] = v;
	}
}

int main() {
	int n;
	cin >> n;
	vector <vector <pair <int, int>>> a(n, vector <pair <int, int>>(n));
	vector <vector <char>> b(n, vector <char>(n, '.'));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> a[i][j].first >> a[i][j].second;
			a[i][j].first--;
			a[i][j].second--;
		}
	dsu.resize(n * n);
	iota(dsu.begin(), dsu.end(), 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j].first != -2) {
				b[a[i][j].first][a[i][j].second] = 'X';
				if (a[a[i][j].first][a[i][j].second].first != a[i][j].first || a[a[i][j].first][a[i][j].second].second != a[i][j].second) {
					cout << "INVALID";
					return 0;
				}
			}
	vector <vector <int>> comp(n, vector <int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			comp[i][j] = i * n + j;
	queue <pair <int, int>> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (b[i][j] == 'X')
				q.push({ i, j });
	vector <vector <bool>> used(n, vector <bool>(n));
	while (!q.empty()) {
		pair <int, int> p = q.front();
		int i = p.first;
		int j = p.second;
		q.pop();
		used[i][j] = true;
		if (i > 0 && !used[i - 1][j] && a[i - 1][j].first == dsu[i * n + j] / n && a[i - 1][j].second == dsu[i * n + j] % n) {
			used[i - 1][j] = true;
			q.push({ i - 1, j });
			b[i - 1][j] = 'D';
			uni(i * n + j, (i - 1) * n + j);
		}
		if (i < n - 1 && !used[i + 1][j] && a[i + 1][j].first == dsu[i * n + j] / n && a[i + 1][j].second == dsu[i * n + j] % n) {
			used[i + 1][j] = true;
			q.push({ i + 1, j });
			b[i + 1][j] = 'U';
			uni(i * n + j, (i + 1) * n + j);
		}
		if (j > 0 && !used[i][j - 1] && a[i][j - 1].first == dsu[i * n + j] / n && a[i][j - 1].second == dsu[i * n + j] % n) {
			used[i][j - 1] = true;
			q.push({ i, j - 1 });
			b[i][j - 1] = 'R';
			uni(i * n + j, i * n + j - 1);
		}
		if (j < n - 1 && !used[i][j + 1] && a[i][j + 1].first == dsu[i * n + j] / n && a[i][j + 1].second == dsu[i * n + j] % n) {
			used[i][j + 1] = true;
			q.push({ i, j + 1 });
			b[i][j + 1] = 'L';
			uni(i * n + j, i * n + j + 1);
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!used[i][j] && a[i][j].first != -2) {
				cout << "INVALID";
				return 0;
			}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (b[i][j] == '.') {
				bool tf = false;
				if (i > 0 && b[i - 1][j] == '.')
					tf = true;
				if (i < n - 1 && b[i + 1][j] == '.')
					tf = true;
				if (j > 0 && b[i][j - 1] == '.')
					tf = true;
				if (j < n - 1 && b[i][j + 1] == '.')
					tf = true;
				if (!tf) {
					cout << "INVALID";
					return 0;
				}
			}
			if (a[i][j].first != -2 && (dsu[i * n + j] / n != a[i][j].first || dsu[i * n + j] % n != a[i][j].second)) {
				cout << "INVALID";
				return 0;
			}
			if (a[i][j].first != -2 && b[i][j] == '.') {
				cout << "INVALID";
				return 0;
			}
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (b[i][j] == '.') {
				q.push({ i, j });
				used[i][j] = true;
				if (i > 0 && b[i - 1][j] == '.') {
					used[i - 1][j] = true;
					b[i][j] = 'U';
					b[i - 1][j] = 'D';
					q.push({ i - 1, j });
				}
				else if (i < n - 1 && b[i + 1][j] == '.') {
					used[i + 1][j] = true;
					b[i][j] = 'D';
					b[i + 1][j] = 'U';
					q.push({ i + 1, j });
				}
				else if (j > 0 && b[i][j - 1] == '.') {
					used[i][j - 1] = true;
					b[i][j] = 'L';
					b[i][j - 1] = 'R';
					q.push({ i, j - 1 });
				}
				else if (j < n - 1 && b[i][j + 1] == '.') {
					used[i][j + 1] = true;
					b[i][j] = 'R';
					b[i][j + 1] = 'L';
					q.push({ i, j + 1 });
				}
			}
			while (!q.empty()) {
				pair <int, int> p = q.front();
				int i = p.first;
				int j = p.second;
				q.pop();
				used[i][j] = true;
				if (i > 0 && !used[i - 1][j]) {
					used[i - 1][j] = true;
					q.push({ i - 1, j });
					b[i - 1][j] = 'D';
				}
				if (i < n - 1 && !used[i + 1][j]) {
					used[i + 1][j] = true;
					q.push({ i + 1, j });
					b[i + 1][j] = 'U';
				}
				if (j > 0 && !used[i][j - 1]) {
					used[i][j - 1] = true;
					q.push({ i, j - 1 });
					b[i][j - 1] = 'R';
				}
				if (j < n - 1 && !used[i][j + 1]) {
					used[i][j + 1] = true;
					q.push({ i, j + 1 });
					b[i][j + 1] = 'L';
				}
			}
		}
	cout << "VALID" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << b[i][j];
		cout << endl;
	}
	return 0;
}