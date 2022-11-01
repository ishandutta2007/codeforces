// October 28, 2018
// http://codeforces.com/contest/1043/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


string s;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG


	cin >> s;
	n = s.length();
	int p = 0;
	char cur = s[0];
	vector<int> chg;
	while (p < n) {
		chg.push_back(p);
		while (p < n && s[p] == cur) p++;
		cur = (cur == 'a' ? 'b' : 'a');
	}
//	for (int i : chg) cout << i << ' ';
//	cout << '\n';
	vector<bool> ans(n, false);
	p = 2;
	char cur_start = s[0];
	while (p < chg.size()) {
		ans[chg[p] - 1] = true;
		p++;
		cur_start = (cur_start == 'a' ? 'b' : 'a');
	}
	if (cur_start == 'b') ans[n - 1] = true;

	for (bool b : ans) {
		cout << (b ? 1 : 0) << ' ';
	}
	cout << '\n';


	return 0;
}