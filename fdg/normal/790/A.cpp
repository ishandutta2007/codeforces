#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	// freopen("input.txt", "r", stdin);

	vector<string> all;
	for (int i = 0; i < 26; ++i) {
		all.push_back("A" + string(1, 'a' + i));
		all.push_back("Z" + string(1, 'a' + i));
	}
	sort(all.begin(), all.end());

	int n, k;
	cin >> n >> k;

	vector<string> ans;
	int ptr = 0;
	for (int i = 0; i < k - 1; ++i) {
		ans.push_back(all[ptr++]);
	}

	for (int i = 0; i < n - k + 1; ++i) {
		string s;
		cin >> s;
		if (s[0] == 'Y') {
			ans.push_back(all[ptr++]);
		} else {
			ans.push_back(ans[ans.size() - k + 1]);
		}
	}

	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}