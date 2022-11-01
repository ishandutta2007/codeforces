#include <iostream>
#include <vector>
#include <string>

using namespace std;

int f(int x, int y) {
	int d = abs(x - y);
	return d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		string alphabet;
		string str;
		cin >> alphabet >> str;
		vector<int> c(26);
		for (int i = 0; i < 26; ++i) {
			c[alphabet[i] - 'a'] = i;
		}
		int ans = 0;
		for (int i = 0; i + 1 < str.size(); ++i) {
			ans += f(c[str[i] - 'a'], c[str[i + 1] - 'a']);
		}
		cout << ans << '\n';
	}
	return 0;
}