#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;


int n;
int c[100000];
map<int, int> m;
set<pair<int, int> > s;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
		m[c[i]]++;
	}
	if (n < 3) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (m[c[i]] > 0) {
			s.insert(make_pair(m[c[i]], c[i]));
			m[c[i]] = 0;
		}
	}
	if ((int)s.size() < 3) {
		cout << 0 << endl;
		return 0;
	}
	vector<pair<int, pair<int, int> > > ans;
	while (true) {
		pair<int, int> p = (*(s.rbegin()));
		s.erase(p);
		pair<int, int> p1 = (*(s.rbegin()));
		s.erase(p1);
		pair<int, int> p2 = (*(s.rbegin()));
		s.erase(p2);
		if (p2.first == 0) {
			break;
		}
		vector<int> v;
		v.push_back(p.second);
		v.push_back(p1.second);
		v.push_back(p2.second);
		sort(v.begin(), v.end());
		ans.push_back(make_pair(v[2], make_pair(v[1], v[0])));
		p.first--;
		p1.first--;
		p2.first--;
		s.insert(p);
		s.insert(p1);
		s.insert(p2);
	}
	cout << (int)ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i].first << ' ' << ans[i].second.first << ' ' << ans[i].second.second << endl;
	}
    return 0;
}