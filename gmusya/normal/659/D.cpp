#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> x(n), y(n);
	for (int i = 0; i < n; i++) 
		cin >> x[i] >> y[i];
	string s;
	for (int i = 1; i < n; i++) {
		if (x[i] == x[i - 1] && y[i] > y[i - 1]) s += 'U';
		if (x[i] == x[i - 1] && y[i] < y[i - 1]) s += 'D';
		if (y[i] == y[i - 1] && x[i] > x[i - 1]) s += 'R';
		if (y[i] == y[i - 1] && x[i] < x[i - 1]) s += 'L';
	}
	int ans = 0;
	for (int i = 0; i < s.size() - 1; i++) {
		string x;
		x += s[i];
		x += s[i + 1];
		ans += (x == "DR" || x == "RU" || x == "UL" || x == "LD");
	}
	cout << ans;
	return 0;
}