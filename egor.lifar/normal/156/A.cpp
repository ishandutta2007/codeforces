#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


string s, t;


int main() {
	cin >> s >> t;
	int n = (int)s.size();
	n += 4000;
	string k;
	for (int i = 0; i < 2000; i++) {
		k += "#";
		s += "#";
	}
	k += s;
	s = k;
	int ans = (int)t.size();
	for (int i = 0; i < n; i++) {
		int l = 0;
		for (int j = i; j < n; j++) {
			if (j - i >= (int)t.size()) {
				break;
			}
			if (s[j] != t[j - i]) {
				l++;
			}
			ans = min(ans, l + (int)t.size() - (j - i + 1));
		}
	}
	for (int i = 0; i < n; i++) {
		int l = 0;
		for (int j = i; j >= 0; j--) {
			if (i - j >= (int)t.size()) {
				break;
			}
			if (s[j] != t[(int)t.size() - 1 - (i - j)]) {
				l++;
			}
			ans = min(ans, l + (int)t.size() - (i - j + 1));
		}
	}
	cout << ans << endl;
	return 0;
}