#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector <vector <int>> tab; //0 -  , 1 - , 2 - 
vector <int> a, b;

int main() {
	cin >> n >> m;
	tab.resize(n);
	for (int i = 0; i < n; i++) tab[i].resize(m);
	a.resize(n);
	b.resize(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) tab[i][j] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i]; j++) {
			if (tab[i][j] == 0) {
				cout << 0;
				return 0;
			}
			tab[i][j] = 2;
		}
		if (a[i] < m) if (tab[i][a[i]] == 2) {
			cout << 0;
			return 0;
		}
		if (a[i] < m) tab[i][a[i]] = 0;
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < b[j]; i++) {
			if (tab[i][j] == 0) {
				cout << 0;
				return 0;
			}
			tab[i][j] = 2;
		}
		if (b[j] < n) if (tab[b[j]][j] == 2) {
			cout << 0;
			return 0;
		}
		if (b[j] < n) tab[b[j]][j] = 0;
	}
	int sum = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (tab[i][j] == 1) sum += 1;
	long long int ans = 1;
	for (int i = 0; i < sum; i++) {
		ans = (ans * 2) % 1000000007;
	}
	cout << ans;
	return 0;
}