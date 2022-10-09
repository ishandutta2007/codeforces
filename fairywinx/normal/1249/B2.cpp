#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

void f(int k, vector<int>& a, vector<int>& used, int& ans, vector<int>& c) {
	used[k] = 1;
	ans++;
	if (used[a[k] - 1] == 1) return;
	c[a[k] - 1] = c[k];
	f(a[k] - 1, a, used, ans, c);
}

int main() {
	int q;
	cin >> q;
	for (int u = 0; u < q; ++u) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		vector<int> c(n);
		vector<int> b;
		int j = 0;
		vector<int> used(n);
		for (int i = 0; i < n; ++i) {
			int ans = 0;
			if (used[i] == 0) {
				c[i] = j;
				++j;
				f(i, a, used, ans, c);
				b.push_back(ans);
			}
		}
		for (int i = 0; i < n; ++i) {
			cout << b[c[i]] << ' ';
		}
		cout << '\n';
	}
}