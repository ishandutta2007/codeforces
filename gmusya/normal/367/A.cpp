#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	vector <int> x(n + 1), y(n + 1), z(n + 1);
	for (int i = 1; i <= n; i++) {
		x[i] = x[i - 1];
		y[i] = y[i - 1];
		z[i] = z[i - 1];
		if (s[i - 1] == 'x')
			x[i]++;
		if (s[i - 1] == 'y')
			y[i]++;
		if (s[i - 1] == 'z')
			z[i]++;
	}
	int m;
	cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		vector <int> a;
		a.push_back(x[r] - x[l - 1]);
		a.push_back(y[r] - y[l - 1]);
		a.push_back(z[r] - z[l - 1]);
		sort(a.begin(), a.end());
		if (a[2] - a[0] <= 1 || r - l <= 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}