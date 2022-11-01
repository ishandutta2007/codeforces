#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	n += 2;
	vector <char> c(n);
	for (int i = 1; i < n - 1; i++)
		cin >> c[i];
	c[0] = 'a';
	c[n - 1] = 'a';
	int points = 0, islands = 0;
	for (int i = 0; i < n; i++)
		points += (c[i] == '.');
	for (int i = 0; i < n - 1; i++)
		islands += (c[i] == '.' && c[i + 1] != '.');
	for (int i = 0; i < m; i++) {
		int x;
		char s;
		cin >> x >> s;
		if ((c[x] == '.' && s == '.') || (c[x] != '.' && s != '.')) {
			cout << points - islands << endl;
			continue;
		}
		if (c[x] == '.') {
			c[x] = s;
			points--;
			if (c[x - 1] != '.' && c[x + 1] != '.')
				islands--;
			if (c[x - 1] == '.' && c[x + 1] == '.')
				islands++;
			cout << points - islands << endl;
			continue;
		}
		if (c[x] != '.') {
			c[x] = s;
			points++;
			if (c[x - 1] != '.' && c[x + 1] != '.')
				islands++;
			if (c[x - 1] == '.' && c[x + 1] == '.')
				islands--;
			cout << points - islands << endl;
			continue;
		}
	}
	return 0;
}