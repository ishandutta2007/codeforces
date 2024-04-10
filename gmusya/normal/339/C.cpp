#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	string s;
	cin >> s;
	vector <bool> k(11);
	for (int i = 1; i < 11; i++)
		k[i] = (s[i - 1] == '1');
	int m;
	cin >> m;
	vector <set <pair <int, int>>> a(m + 1);
	a[0].insert({ 0, 0 });
	for (int i = 0; i < m; i++)
		for (auto it = a[i].begin(); it != a[i].end(); it++) {
			pair <int, int> p = *it;
			int last = p.first;
			int bal = p.second;
			for (int j = 1; j < 11; j++) {
				if (last == j || !k[j] || bal - j >= 0)
					continue;
				a[i + 1].insert({ j, abs(bal - j) });
			}
		}
	if (a[m].size() == 0) {
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	vector <int> ans;
	int balance = a[m].begin()->second;
	int lasteckiy = 0;
	while (m > 0) {
		for (auto it = a[m].begin(); it != a[m].end(); it++) {
			pair <int, int> p = *it;
			int last = p.first;
			int bal = p.second;
			if (bal == balance && lasteckiy != last) {
				ans.push_back(last);
				balance = abs(bal - last);
				lasteckiy = last;
				break;
			}
		}
		m--;
	}
	reverse(ans.begin(), ans.end());
	for (auto now : ans)
		cout << now << " ";
	return 0;
}