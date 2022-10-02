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
#include <unordered_map>


using namespace std;

int k;
int n;
string s;
int g[2001][26];
vector<int> v[2001][26];


int main() {
	cin >> k;
	cin >> s;
	n = (int)s.size();
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			g[i][s[j] - 'a']++;
			v[i][s[j] - 'a'].push_back(j);
		}
	}
	int q;
	cin >> q;
	for (int ii = 0; ii < q; ii++) {
		int kk;
		char s1;
		cin >> kk >> s1;
		int k1 = 0;
		for (int i = 0; i < k; i++) {
			if (k1 + g[i][s1 - 'a'] < kk) {
				k1 += g[i][s1 - 'a'];
				continue;
			}
		//	cout << i + 1 << endl;
			k1 = kk - k1;
			for (int j = 0; j < (int)v[i][s1 - 'a'].size(); j++) {
				if (v[i][s1 - 'a'][j] == -1) {
					continue;
				}
		//		cout << j + 1 << endl;
				k1--;
				if (k1 == 0) {
					v[i][s1 - 'a'][j] = -1;
					g[i][s1 - 'a']--;
					break;
				}
			}
			break;
		}
	}
	for (int i = 0; i < k; i++) {
		vector<int> t;
		for (int j = 0; j < 26; j++) {
			for (int g = 0; g < (int)v[i][j].size(); g++) {
				if (v[i][j][g] == -1) {
					continue;
				}
				t.push_back(v[i][j][g]);
			}
		}
		sort(t.begin(), t.end());
		for (int j = 0; j < (int)t.size(); j++) {
			cout << s[t[j]];
		}
	}
	cout << endl;
    return 0;
}