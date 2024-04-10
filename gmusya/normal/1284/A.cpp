#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector <string> s(n), t(m);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < m; i++)
		cin >> t[i];
	vector <string> ans(n * m);
	for (int i = 0; i < n * m; i++)
		ans[i] = s[i % n] + t[i % m];
	vector <string> answer;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		answer.push_back(ans[(x - 1) % (n * m)]);
	}
	for (auto now : answer)
		cout << now << '\n';
	return 0;
}