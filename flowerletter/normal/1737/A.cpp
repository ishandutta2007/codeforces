#include <bits/stdc++.h>
using namespace std;

int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(0);
	int T;
	for(cin >> T; T; T --) {
		int n, k;
		cin >> n >> k;
		string str;
		cin >> str;
		vector<int> c(26);
		for(auto a : str) c[a - 'a'] ++;
		for(int i = 0; i < k; i ++) {
			int p = find(c.begin(), c.end(), 0) - c.begin();
			p = min(p, n / k);
			cout << char(p + 'a');
			for(int i = 0; i < p; i ++) c[i] --;
			// for(int i = 0; i < 26; i ++) cout << c[i] << ' '; cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}