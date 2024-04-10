#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector <char> gor, ver;
vector <vector <bool>> used;

void dfs(int y, int x) {
	used[y][x] = true;
	if (gor[y] == '<')
		for (int i = 1; x - i >= 0; i++)
			if (!used[y][x - i])
				dfs(y, x - i);
	if (gor[y] == '>')
		for (int i = 1; x + i <= m - 1; i++)
			if (!used[y][x + i])
				dfs(y, x + i);
	if (ver[x] == '^')
		for (int i = 1; y - i >= 0; i++)
			if (!used[y - i][x])
				dfs(y - i, x);
	if (ver[x] == 'v')
		for (int i = 1; y + i <= n - 1; i++)
			if (!used[y + i][x])
				dfs(y + i, x);
}

int main() {
	cin >> n >> m;
	gor.resize(n);
	ver.resize(m);
	for (int i = 0; i < n; i++)
		cin >> gor[i];

	for (int i = 0; i < m; i++)
		cin >> ver[i];
	bool tf = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			used.resize(0);
			used.resize(n);
			for (int i = 0; i < n; i++)
				used[i].resize(m);
			dfs(i, j);
			for (int y = 0; y < n; y++) 
				for (int x = 0; x < m; x++) 
					if (!used[y][x])
						tf = false;
		}
	if (tf)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}