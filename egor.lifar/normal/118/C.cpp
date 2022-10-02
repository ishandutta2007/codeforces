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


using namespace std;


int n, k;
vector<string> f;
int ans1[101];


int main() {
	cin >> n >> k;
	string s;
	cin >> s;
	int ans = 1000 * 1000 * 1000;
	for (int i = 0; i < 10; i++) {
		int g = 0;
		vector<pair<int, int> > v;
		for (int j = 0; j < n; j++) {
			if (s[j] == i + '0') {
				g++;
			} else {
				v.push_back(make_pair(abs(s[j] - i - '0'), (s[j] < i + '0' ? -j: j)));
			}
		}
		sort(v.begin(), v.end());
		for (int j = 0; j < (int)v.size(); j++) {
			if (g < k) {
				g++;
				ans1[i] += v[j].first;
			}
		}
		ans = min(ans, ans1[i]);
	}
	for (int i = 0; i < 10; i++) {
		int g = 0;
		vector<pair<int, pair<int, int> > > v;
		for (int j = 0; j < n; j++) {
			if (s[j] == i + '0') {
				g++;
			} else {
				v.push_back(make_pair(abs(s[j] - i - '0'), (s[j] < i + '0' ? make_pair(1, -j): make_pair(-1, j))));
			}
		}
		sort(v.begin(), v.end());
		string s1 = s;
		for (int j = 0; j < (int)v.size(); j++) {
			if (g < k) {
				g++;
				s1[abs(v[j].second.second)] = i + '0';
			}
		}
		if (ans == ans1[i]) {
			f.push_back(s1);
			//cout << s1 << endl;
		}
	}

	cout << ans << endl;
	sort(f.begin(), f.end());
	cout << f[0] << endl;
    return 0;
}