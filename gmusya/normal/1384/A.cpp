#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector <string> s(n + 1);
		for (int i = 0; i < 51; i++)
			s[0] += 'a';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < a[i]; j++)
				s[i + 1] += s[i][j];
			if (s[i][a[i]] == 'a') s[i + 1] += 'b';
			else s[i + 1] += 'a';
			while (s[i + 1].size() < 51) s[i + 1] += 'a';
		}
		for (auto &now : s)
			cout << now << '\n';
	}
	return 0;
}