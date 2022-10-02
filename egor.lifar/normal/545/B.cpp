#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
 

using namespace std;


string s, s1;


int main() {
	cin >> s >> s1;
	int n = (int)s.size();
	int t = 0;
	int t1 = 0;
	string ans;
	ans.resize(n);
	for (int j = 0; j < n; j++) {
		if (s[j] != s1[j]) {
			if (t <= t1) {
				ans[j] = s1[j];
				t++; 
			} else {
				ans[j] = s[j];
				t1++;
			}
		} else {
			ans[j] = s[j];
		}
	}
	if (t != t1) {
		cout << "impossible" << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}