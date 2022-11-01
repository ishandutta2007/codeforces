#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <pair <int, int>> x;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		x.push_back({ l, 0 });
		x.push_back({ r, 1 });
	}
	sort(x.begin(), x.end());
	int bal = 0;
	for (int i = 0; i < x.size(); i++) {
		if (x[i].second == 0)
			bal++;
		else
			bal--;
		if (bal > 2) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}