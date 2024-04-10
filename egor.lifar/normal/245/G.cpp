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


int m;
map<string, int> mm;
vector<int> v[100000];
int t[100000];
bool bad[10002][10002];


int main() {
	cin >> m;	
	vector<string> s;
	int sh = 0;
	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		s.push_back(a);
		s.push_back(b);
		if (mm.find(a) == mm.end()) {
			mm[a] = sh;
			sh++;
		}
		if (mm.find(b) == mm.end()) {
			mm[b] = sh;
			sh++;
		}
		v[mm[a]].push_back(mm[b]);
		v[mm[b]].push_back(mm[a]);
	}
	sort(s.begin(), s.end());
	s.resize(distance(s.begin(), unique(s.begin(), s.end())));
	cout << (int)s.size() << endl;
	int n = (int)s.size();
	for (int i = 0; i < n; i++) {
		t[i] = mm[s[i]];
		//cout << (int)v[t[i]].size() << endl;
 		for (int j = 0; j < (int)v[t[i]].size(); j++) {
			bad[t[i]][v[t[i]][j]] = true;
		}
		bad[t[i]][t[i]] = true;
		int a = t[i];
		vector<int> f;
		f.resize(n);
		int ans = -1;
		for (int j = 0; j < n; j++) {
			if (!bad[a][j]) {
				for (int g = 0; g < (int)v[j].size(); g++) {
					int h = v[j][g];
					if (bad[a][h]) {
						f[j]++;
					}
				}
				ans = max(ans, f[j]);
			}
		}
		int t = 0;
		for (int j = 0; j < n; j++) {
			if (!bad[a][j]) {
				if (f[j] == ans) {
					t++;
				}
			}
		}
		cout << s[i] << ' ' << t << endl;
	}
    return 0;
}