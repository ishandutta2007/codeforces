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
int b[201][201];
bool m[201];
int g[201];


int main() {
	cin >> n;
	int s = (n * (n - 1) / 2);
	vector<int> v;
	for (int i = 0; i < s; i++) {
		int k;
		cin >> k;
		vector<int> c;
		c.resize(k);
		for (int j = 0; j < k; j++) {
			cin >> c[j];
			g[c[j]]++;
			v.push_back(c[j]);
		}
		if (n == 2) {
			cout << (int)v.size() / 2;
			for (int j = 0; j < (int)v.size() / 2; j++) {
				cout << ' ' << v[j];
			}
			cout << endl;
			cout << (int)v.size() - (int)v.size() / 2;
			for (int j = (int)v.size() / 2; j < (int)v.size(); j++) {
				cout << ' ' << v[j];
			}
			cout << endl;
			return 0;
		}
		for (int j = 0; j < k; j++) {
			for (int g = j + 1; g < k; g++) {
				b[c[j]][c[g]]++;
				b[c[g]][c[j]]++;
			}
		}
	}
	sort(v.begin(), v.end());
	v.resize(distance(v.begin(), unique(v.begin(), v.end())));
	for (int i = 0; i < (int)v.size(); i++) {
		if (m[v[i]]) {
			continue;
		}
		vector<int> s;
		s.push_back(v[i]);
		m[v[i]] = true;
		for (int j = i + 1; j < (int)v.size(); j++) {
			if (b[v[i]][v[j]] == g[v[i]]) {
				m[v[j]] = true;
				s.push_back(v[j]);
			}
		}
		cout << (int)s.size();
		for (int j = 0; j < (int)s.size(); j++) {
			cout << ' ' << s[j];
		}
		cout << endl;
	}
 	return 0;
}