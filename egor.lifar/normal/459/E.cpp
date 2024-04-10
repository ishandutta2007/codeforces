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


int n, m;
int ans[300001];
map<int, vector<pair<int, int> > > v;
map<int, int> ans1;


int main() {
	cin >> n >> m;
	vector<int> s;
	for (int i = 0; i < m; i++) {
		int a, b, l;
		scanf("%d %d %d", &a, &b, &l);
		v[l].push_back(make_pair(a - 1, b - 1));
		s.push_back(l);
	} 	
	sort(s.begin(), s.end());
	s.resize(distance(s.begin(), unique(s.begin(), s.end())));
	for (int i = 0; i < (int)s.size(); i++) {
		ans1.clear();
		for (int j = 0; j < (int)v[s[i]].size(); j++) {
			ans1[v[s[i]][j].first] = ans[v[s[i]][j].first];
			ans1[v[s[i]][j].second] = ans[v[s[i]][j].second];
		}
		for (int j = 0; j < (int)v[s[i]].size(); j++) {
			ans[v[s[i]][j].second] = max(ans[v[s[i]][j].second], ans1[v[s[i]][j].first] + 1);
		}
 	}
 	int k = 0;
 	for (int i = 0; i < n; i++) {
 		k = max(k, ans[i]);
 	}
 	cout << k << endl;
 	return 0;
}//