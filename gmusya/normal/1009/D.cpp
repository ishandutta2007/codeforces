#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <pair <int, int>> a;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			if (a.size() == m)
				break;
			if (gcd(i, j) == 1)
				a.push_back({ i, j });
		}
	if (a.size() < m || m < n - 1	) {
		cout << "Impossible";
		return 0;
	}
	cout << "Possible" << endl;
	for (auto now : a)
		cout << now.first << " " << now.second << endl;
	return 0;
}