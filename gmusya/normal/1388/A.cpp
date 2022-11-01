#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100;

int main() {
	/*vector <bool> isp(MAXN + 1);
	vector <int> p, lp(MAXN + 1);
	for (int i = 2; i <= MAXN; i++) {
		if (!lp[i]) lp[i] = i, isp[i] = true, p.push_back(i);
		for (int j = 0; j < p.size() && p[j] <= lp[i] && p[j] * i <= MAXN; j++)
			lp[i * p[j]] = p[j];
	}
	for (auto &now : p)
		cout << now << ' ';*/
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n <= 30) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		if (n == 36 || n == 40 || n == 44)
			cout << 6 << ' ' << 10 << ' ' << 15 << ' ' << n - 31 << '\n';
		else
			cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << n - 30 << '\n';
	}
	return 0;
}