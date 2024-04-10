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
int d[1000001];


int main() {
	cin >> s;
	int n = (int)s.size();
	vector<int> v;
	int ans = 0;
//	v.push_back(0);
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			v.push_back(i);
		} else {
			if (!v.empty()) {
				d[i] = i - v.back() + 1;
				v.pop_back();
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (i - d[i] >= 0) {
			d[i] += d[i - d[i]];
		}
		ans = max(ans, d[i]);
	}	
	cout << ans << ' ';
	if (ans == 0) {
		cout << 1 << endl;
		return 0;
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] == ans) {
			k++;
		}
	}
	cout << k << endl;
    return 0;
}