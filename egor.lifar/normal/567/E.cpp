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


#define INF 1000000000000000000LL


int n, m;
vector<pair<int, long long> > v[100000], v1[100000];
long long d[100001];
long long d1[100001];
set<pair<long long, int> > s;


void dijkstra(int st) {
	for (int i = 0; i < n; i++) {
		if (i != st) {
			d[i] = INF;
			s.insert(make_pair(INF, i));
		}
	}
	d[st] = 0;
	s.insert(make_pair(0, st));
	while (!s.empty()) {
		int x = (*(s.begin())).second;
		s.erase(*(s.begin()));
		for (int i = 0; i < (int)v[x].size(); i++) {
			int y = v[x][i].first;
			if (d[y] > d[x] + v[x][i].second) {
				s.erase(make_pair(d[y], y));
				d[y] = d[x] + v[x][i].second;
				s.insert(make_pair(d[y], y));
			}
		}
	}
}



void dijkstra1(int st) {
	for (int i = 0; i < n; i++) {
		if (i != st) {
			d1[i] = INF;
			s.insert(make_pair(INF, i));
		}
	}
	d1[st] = 0;
	s.insert(make_pair(0, st));
	while (!s.empty()) {
		int x = (*(s.begin())).second;
		s.erase(*(s.begin()));
		for (int i = 0; i < (int)v1[x].size(); i++) {
			int y = v1[x][i].first;
			if (d1[y] > d1[x] + v1[x][i].second) {
				s.erase(make_pair(d1[y], y));
				d1[y] = d1[x] + v1[x][i].second;
				s.insert(make_pair(d1[y], y));
			}
		}
	}
}


int ans[100001];
int c[100001];
long long w[100001];
map<int, vector<pair<int, int> > > g, g1;
bool good[100001];
map<int, int> mm;


bool les(pair<pair<long long, long long>, int> a, pair<pair<long long, long long>, int> b) {
	return a.first.second > b.first.second;
}


int main() {
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	s--;
	t--;
	vector<pair<int, int> > e;
	for (int i = 0; i < m; i++) {
		int a, b, l;
		scanf("%d %d %d", &a, &b, &l);
		w[i] = l;
		a--;
		b--;
		e.push_back(make_pair(a, b));
		v[a].push_back(make_pair(b, l));
		v1[b].push_back(make_pair(a, l));
	}
	dijkstra(s);
	dijkstra1(t);
	vector<pair<pair<long long, long long>, int> > ds;
	for (int i = 0; i < m; i++) {
		int a = e[i].first;
		int b = e[i].second;
		if (d[a] + d1[b] + w[i] == d[t]) {
			ds.push_back(make_pair(make_pair(d[a], d[b]), i));
		}
	}
	sort(ds.begin(), ds.end(), les);
	set<pair<long long, long long> > ss, ss1;
	for (int i = 0; i < (int)ds.size(); i++) {
		long long l = ds[i].first.first, r = ds[i].first.second;
		auto it = ss.lower_bound(make_pair(l, -1LL));
		if (it == ss.end() || it->second >= r) {
			ss.insert(make_pair(r, l));
		} else {
			long long l1 = it->second, r1 = it->first;
            ss1.insert(*it);
            ss1.insert(make_pair(r1, min(l1, l)));
            ss.erase(it);
            ss.insert(make_pair(r1, min(l1, l)));
		}
	}
	for (int i = 0; i < (int)ds.size(); i++) {
		long long l = ds[i].first.first, r = ds[i].first.second;
        auto it = ss.find(make_pair(r, l));
        auto it2 = ss1.find(make_pair(r, l));
        if(it != ss.end() && it2 == ss1.end()) {
            good[ds[i].second] = true;
        }
	}
	for (int i = 0; i < m; i++) {
		int a = e[i].first;
		int b = e[i].second;
		if (good[i]) {
			printf("YES\n");
		} else {
			if (d[t] - d[a] - d1[b] - 1LL > 0LL) {
				printf("CAN %I64d\n", w[i] - (d[t] - d[a] - d1[b] - 1));
			} else {
				printf("NO\n");
			}
		}
	}
    return 0;
}