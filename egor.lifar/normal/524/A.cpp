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


using namespace std;


int n, k;
map<int, vector<int> > m;
map<int, vector<int> > m2;
map<int, set<int> > m1;


int main() {
	cin >> n >> k;
	vector<int> s;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		m[a].push_back(b);
		m[b].push_back(a);
		m1[a].insert(b);
		m1[b].insert(a);
		s.push_back(a);
		s.push_back(b);
	}
	sort(s.begin(), s.end());
	s.resize(distance(s.begin(), unique(s.begin(), s.end())));
	for (int i = 0; i < (int)s.size(); i++) {
		int u = s[i];
		for (int j = 0; j < (int)s.size(); j++) {
			if (i != j && m1[s[i]].find(s[j]) == m1[s[i]].end()) {
				int t = 0;
				for (int k = 0; k < (int)m[s[j]].size(); k++) {
					int g = m[s[j]][k];
					if (m1[g].find(u) != m1[g].end()) {
						t++;
					}
				}
				//cout << (double)m[s[j]].size() / 100.0 * 1.0 * double(k) << endl;
				if ((double)m[s[j]].size() / 100.0 * 1.0 * double(k) <= double(t)) {
					m2[s[j]].push_back(u);
				}
			}
		}
	}
	for (int i = 0; i < (int)s.size(); i++) {
		sort(m2[s[i]].begin(), m2[s[i]].end());
		m2[s[i]].resize(distance(m2[s[i]].begin(), unique(m2[s[i]].begin(), m2[s[i]].end())));
		cout << s[i] << ':' << ' ' <<  (int)m2[s[i]].size();
		for (int j = 0; j < (int)m2[s[i]].size(); j++) {
			cout << ' ' << m2[s[i]][j];
		}
		cout << endl;
	}
	return 0;
}