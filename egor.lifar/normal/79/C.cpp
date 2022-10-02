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


int n;
string s;
string a[10];
set<pair<int, int> > ss;
set<pair<int, int> > ss1;
vector<int> t[100000];


int main() {
	cin >> s;
	cin >> n;
	int m = (int)s.size();
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		int l = (int)a[i].size();
		for (int j = 0; j <= m - l; j++) {
			bool b = true;
			for (int g = j; g < j + l; g++){
				if (s[g] != a[i][g - j]) {
					b = false;
					break;
				}
			}
			if (b) {
			//	cout << j + 1 << ' ';
				ss.insert(make_pair(j + l - 1, j));
				ss1.insert(make_pair(j, j + l - 1));
				t[j + l - 1].push_back(j);
			}
		}
		//cout << endl;
	}	
	pair<int, int> ans = make_pair(0, 0);
	for (int i = (int)s.size() - 1; i >= 0; i--) {
		int l;
		if (ss.empty()) {
			l = 0;
		} else {
			pair<int, int> a = *(ss.rbegin());
			l = a.second + 1;
			a = *(ss1.rbegin());
			l = max(l, a.first + 1);
		}
		//cout << l << endl;
		if (i >= l) {
			ans = max(ans, make_pair(i - l + 1, l));
		//	cout << "opa" << endl;
		}
		for (int j = 0; j < (int)t[i].size(); j++) {
			int h = t[i][j];
			ss.erase(make_pair(i, h));
			ss1.erase(make_pair(h, i));
		}
	}	
	cout << ans.first << ' ' << ans.second << endl;
    return 0;
}