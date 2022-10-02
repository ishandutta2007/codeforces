#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n;
string s[100];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	bool t = false, t1 = false;
	for (int i = 0; i < n; i++) {
		bool b = true;
		for (int j = 0; j < n; j++) {
			if (s[i][j] == '.') {
				b = false;
			}
		}
		if (b) {
			t = true;
		}
	}
	for (int i = 0; i < n; i++) {
		bool b = true;
		for (int j = 0; j < n; j++) {
			if (s[j][i] == '.') {
				b = false;
			}
		}
		if (b) {
			t1 = true;
		}
	}
	if (t && t1) {
		cout << -1 << endl;
		return 0;
	}
	vector< pair<int, int> > ans;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[j][i] == '.') {
				ans.push_back(make_pair(j + 1, i + 1));
				break;
			}
		}
	}
	if (ans.size() == n) {
		for (int i = 0; i < n; i++) {
			cout << ans[i].first << ' ' << ans[i].second << endl;
		}
	} else {
		ans.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (s[i][j] == '.') {
					ans.push_back(make_pair(i + 1, j + 1));
					break;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i].first << ' ' << ans[i].second << endl;
		}
	}
	return 0;
}