#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, t;
	cin >> n >> m >> t;
	vector <vector <char>> c(n, vector <char>(m));
	vector <vector <int>> fir(n, vector <int>(m, INF));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];
	vector <vector <char>> old = c;
	vector <vector <char>> d = c;
	int cnt = 0;
	set <pair <int, int>> s;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int kek = 0;
			kek += (i == 0) || (c[i][j] != c[i - 1][j]);
			kek += (j == 0) || (c[i][j] != c[i][j - 1]);
			kek += (i == n - 1) || (c[i][j] != c[i + 1][j]);
			kek += (j == m - 1) || (c[i][j] != c[i][j + 1]);
			if (kek != 4) {
				d[i][j] = '1' - d[i][j] + '0';
				s.insert({ i, j });
			}
		}
	swap(c, d);
	while (!s.empty()) {
		cnt++;
		set <pair <int, int>> k;
		for (auto &now : s) 
			fir[now.first][now.second] = cnt;
		while (!s.empty()) {
			auto now = *s.begin();
			s.erase(s.begin()); 
			int i = now.first;
			int j = now.second;
			if (i > 0 && fir[i - 1][j] == INF)
				k.insert({ i - 1, j });
			if (j > 0 && fir[i][j - 1] == INF)
				k.insert({ i, j - 1 });
			if (i + 1 < n && fir[i + 1][j] == INF)
				k.insert({ i + 1, j });
			if (j + 1 < m && fir[i][j + 1] == INF)
				k.insert({ i, j + 1 });
		}
		set <pair <int, int>> news;
		for (auto &now : k) {
			int i = now.first;
			int j = now.second;
			int kek = 0;
			kek += (i == 0) || (c[i][j] != c[i - 1][j]);
			kek += (j == 0) || (c[i][j] != c[i][j - 1]);
			kek += (i == n - 1) || (c[i][j] != c[i + 1][j]);
			kek += (j == m - 1) || (c[i][j] != c[i][j + 1]);
			if (kek != 4) {
				d[i][j] = '1' - d[i][j] + '0';
				news.insert({ i, j });
			}
		}
		swap(c, d);
		swap(news, s);
	}
	while (t--) {
		int i, j;
		long long p;
		cin >> i >> j >> p;
		if (p > INF) p = (INF - 2 + p % 2);
		i--, j--;
		char ans;
		if (fir[i][j] > p) cout << old[i][j];
		else if ((p - fir[i][j]) % 2) cout << old[i][j];
		else if (old[i][j] == '1') cout << 0;
		else cout << 1;
		cout << '\n';
	}
	return 0;
}