#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector <vector <int>> g(k);
		for (int i = 0; i < k; i++) {
			int c;
			cin >> c;
			g[i].resize(c);
			for (int j = 0; j < c; j++)
				cin >> g[i][j];
		}
		cout << "? " << n << ' ';
		for (int i = 1; i <= n; i++)
			cout << i << ' ';
		cout << endl;
		int MAX;
		cin >> MAX;
		int L = 0;
		int R = k - 1;
		while (L != R) {
			int M = (L + R) / 2;
			vector <bool> used(n + 1);
			for (int i = 0; i <= M; i++)
				for (int j = 0; j < g[i].size(); j++)
					used[g[i][j]] = true;
			vector <int> query;
			for (int i = 1; i <= n; i++)
				if (!used[i])
					query.push_back(i);
			cout << "? " << query.size() << ' ';
			for (int i = 0; i < query.size(); i++)
				cout << query[i] << ' ';
			cout << endl;
			int x;
			cin >> x;
			if (x != MAX) R = M;
			else L = M + 1;
		}
		vector <int> password(k, MAX);
		int pos = L;
		vector <bool> used(n + 1);
		for (int j = 0; j < g[pos].size(); j++)
			used[g[pos][j]] = true;
		vector <int> query;
		for (int i = 1; i <= n; i++)
			if (!used[i])
				query.push_back(i);
		cout << "? " << query.size() << ' ';
		for (int i = 0; i < query.size(); i++)
			cout << query[i] << ' ';
		cout << endl;
		cin >> password[pos];
		cout << "! ";
		for (int i = 0; i < k; i++)
			cout << password[i] << ' ';
		cout << endl;
		string s;
		cin >> s;
	}
	return 0;
}