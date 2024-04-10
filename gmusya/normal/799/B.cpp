#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> p(n), a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	
	vector <set <int>> s(3);
	for (int i = 0; i < n; i++) {
		s[a[i] - 1].insert(p[i]);
		s[b[i] - 1].insert(p[i]);
	}
	int m;
	cin >> m;
	vector <int> ans;
	while (m--) {
		int c;
		cin >> c;
		if (s[c - 1].size() == 0) {
			ans.push_back(-1);
			continue;
		}
		int x = *s[c - 1].begin();
		ans.push_back(x);
		s[c - 1].erase(x);
		for (int i = 0; i < 3; i++)
			if (s[i].find(x) != s[i].end())
				s[i].erase(x);
	}
	for (auto now : ans)
		cout << now << " ";
	return 0;
}