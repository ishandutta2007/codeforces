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


string s;
vector<int> v;


int main() {
	cin >> s;
	int ll = (int)s.size();
	int g = 0;
	for (int i = 0; i < ll; i++) {
		if (s[i] == ',') {
			v.push_back(g);
			g = 0;
		} else {
			g *= 10;
			g += s[i] - '0';
		}
	}
	v.push_back(g);
	sort(v.begin(), v.end());
	v.resize(distance(v.begin(), unique(v.begin(), v.end())));
	int n = (int)v.size();
	int l = 0;
	while (l < n) {
		int t = v[l];
		int l1 = l;
		while (l + 1 < n && v[l + 1] - t <= l + 1 - l1) {
			l++;
		}
		if (l == l1) {
			cout << t;
			if (l != n - 1) {
				cout << ',';
			}
		} else {
			cout << t << '-' << v[l];
			if (l != n - 1) {
				cout << ',';
			}
		}
		l++;
	}
	cout << endl;
 	return 0;
}