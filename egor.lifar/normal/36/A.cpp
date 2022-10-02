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


int n;
string s;


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	cin >> s;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			v.push_back(i);
		}
	}
	set<int> s;
	for (int j = 0; j < (int)v.size() - 1; j++) {
		s.insert(v[j + 1] - v[j]);
	}
	if ((int)s.size() == 1) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
 	return 0;
}