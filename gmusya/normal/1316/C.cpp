#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, p;
	cin >> n >> m >> p;
	int x = max(n, m);
	vector <int> a(x), b(x);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	int posa;
	for (int i = 0; i < n; i++)
		if (a[i] % p) {
			posa = i;
			break;
		}
	int posb;
	for (int i = 0; i < m; i++)
		if (b[i] % p) {
			posb = i;
			break;
		}
	cout << posa + posb;
	return 0;
}