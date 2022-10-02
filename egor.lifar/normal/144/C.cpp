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


string s;
string p;
int c[100000][26];
int t[26];


int main() {
	cin >> s >> p;
	int n = (int)s.size();
	int m = (int)p.size();
	for (int i = 0; i < n; i++) {
		if (s[i] != '?') {
			c[i][s[i] - 'a']++;
		}
		for (int j = 0; j < 26; j++) {
			c[i][j] += (i > 0 ? c[i - 1][j]: 0);
		}
	}
	for (int i = 0; i < m; i++) {
		t[p[i] - 'a']++;
	}
	int ans = 0;
	for (int i = m - 1; i < n; i++) {
		bool b = true;
		for (int j = 0; j < 26; j++) {
			if (c[i][j] - (i - m >= 0 ? c[i - m][j]: 0) > t[j]) {
				b = false;
			}
		}	
		if (b) {
			ans++;
		}
	}
	cout << ans << endl;
    return 0;
}