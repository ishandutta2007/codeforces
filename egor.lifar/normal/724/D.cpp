#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>


using namespace std;


int m;
string s;
vector<int> pos[27];
bool good[100001];
int cnt[27];


int main() {
	cin >> m;
	string s;
	cin >> s;
	int n = (int)s.size();
	for (int i = 0; i < n; i++) {
		pos[s[i] - 'a'].push_back(i);
	}
	string ans;
	for (int i = 0; i < 26; i++) {
		cnt[i] = (int)pos[i].size();
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j <= n - m; j++) {
			if (!good[j]) {
				auto it = upper_bound(pos[i].begin(), pos[i].end(), j + m - 1);
				if (it != pos[i].begin()) {
					it--;
					int s = *it;
					if (s >= j) {
						ans += char('a' + i);
						cnt[i]--;
						for (int k = j; k <= s; k++) {
							good[k] = 1;
						}
					}
				}
			}
 		}
 		bool t = 1;
 		for (int j = 0; j <= n - m; j++) {
			if (!good[j]) {
				t = 0;
			}
		}
		if (!t) {
			for (int j = 0; j < cnt[i]; j++) {
				ans += char('a' + i);
			}
			cnt[i] = 0;
		}
	}
	cout << ans << endl;
	return 0;
}