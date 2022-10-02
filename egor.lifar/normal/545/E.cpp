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


#define MAXN 300000
#define INF 100000000000000000LL


int n, m;
vector<pair<int, long long> > v[MAXN];
set<pair<long long, int> > s;
long long d[300000];
map<pair<int, int>, int> mm;
vector<int> ans;
long long sum = 0;
int k[300000];
long long c[300000];


void dijkstra(int u) {
	for (int i = 0; i < n; i++) {
		d[i] = INF;
		s.insert(make_pair(INF, i));
	}
	s.erase(make_pair(d[u], u));
	d[u] = 0;
	s.insert(make_pair(d[u], u));
	while (!s.empty()) {
		pair<long long, int> h = *(s.begin());
		s.erase(h);
		int x = h.second;
		for (int i = 0; i < (int)v[x].size(); i++) {
			int g = v[x][i].first;
			if (d[g] >= v[x][i].second + d[x]) {
				s.erase(make_pair(d[g], g));
				d[g] = v[x][i].second + d[x];
				k[g] = x;
				c[g] = v[x][i].second;
				s.insert(make_pair(d[g], g));
			}
		}
	}
}


int main() {
	cin >> n >> m;
	vector<pair<int, pair<int, int> > > p;
	for (int i = 0; i < m; i++) {
		int a, b, l;
		scanf("%d %d %d", &a, &b, &l);
		v[a - 1].push_back(make_pair(b - 1, l));
		v[b - 1].push_back(make_pair(a - 1, l));
		mm[make_pair(a - 1, b - 1)] = i + 1;
		mm[make_pair(b - 1, a - 1)] = i + 1;
	}
	int u;
	cin >> u;
	u--;
	dijkstra(u);
	for (int i = 0; i < n; i++) {
		if (i != u) {
			sum += c[i];
			ans.push_back(mm[make_pair(k[i], i)]);
		}
	}
	//cout << d[1] << endl;
	//cout << d[0] << endl;
	cout << sum << endl;
	for (int j = 0; j < (int)ans.size(); j++) {
		cout << ans[j] << ' ';
	}
	cout << endl;
	return 0;
}