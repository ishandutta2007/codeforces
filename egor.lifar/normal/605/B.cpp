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
#include <vector>


using namespace std;


int n, m;
int a[200001], b[200001];
vector<pair<int, pair<int, int> > > v;
pair<int, int> ans[200001];
bool used[200001];


int main () {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a[i], &b[i]);
		v.push_back(make_pair(a[i], make_pair(1 - b[i], i)));
	}
	sort(v.begin(), v.end());
	int s = 2, f = 3;
	int l = 0;
	used[0] = true;
	for (int i = 0; i < m; i++) {
		if (v[i].second.first == 0) {
			l++;
			used[l] = true;
			ans[v[i].second.second] = make_pair(1, l + 1);
		} else {
			ans[v[i].second.second] = make_pair(s, f);
			if (!used[s - 1] || !used[f - 1]) {
				cout << -1 << endl;
				//cout << i + 1 << endl;
				return 0;
			}
			s++;
			if (s == f) {
				f++;
				s = 2;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}