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
#include <cstring>
#include <cmath>


using namespace std;


int n, m, k;
vector<pair<int, int> > v[100001];
long long dist[100001];
bool bad[100001];


int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, l;
		scanf("%d %d %d", &a, &b, &l);
		a--;
		b--;
		v[a].push_back(make_pair(b, l));
		v[b].push_back(make_pair(a, l));
	}
	if (k == 0 || k == n) {
		cout << -1 << endl;
		return 0;
	}
	set<pair<long long, int> > s;
	for (int i = 0; i < n; i++) {
		dist[i] = 1000000000000000000LL;
	}
	for (int i = 0; i < k; i++) {
		int a;
		scanf("%d", &a);
		a--;
		bad[a] = 1;
		dist[a] = 0LL;
		s.insert(make_pair(0LL, a));
	}
	while (!s.empty()) {
		int a = s.begin()->second;
		s.erase(*s.begin());
		for (int i = 0; i < (int)v[a].size(); i++) {
			int h = v[a][i].first;
			if (dist[h] > dist[a] + v[a][i].second) {
				if (s.find(make_pair(dist[h], h)) != s.end()) {
					s.erase(make_pair(dist[h], h));
				}
				dist[h] = dist[a] + v[a][i].second;
				s.insert(make_pair(dist[h], h));
			}
		}
	}
	long long ans = 1000000000000000000LL;
	for (int i = 0; i < n; i++) {
		if (!bad[i]) {
			ans = min(ans, dist[i]);
		}
	}
	if (ans == 1000000000000000000LL) {
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;
    return 0;
}