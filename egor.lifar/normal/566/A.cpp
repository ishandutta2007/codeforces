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


#define INF 1000000001



int n;
vector<pair<string, int> > v;
char c[800001];
int where[200001];
int who[200001];
int lcp[200001];
int d[1000001];
int d1[1000001];


void change(int i, int x) {
	d[i] = x;
	while (i / 2 > 0) {
		i /= 2;
		d[i] = d[i * 2] + d[i * 2 + 1];
	}
}


void change1(int i, int x) {
	d1[i] = x;
	while (i / 2 > 0) {
		i /= 2;
		d1[i] = min(d1[i * 2], d1[i * 2 + 1]);
	}
}


int rmq(int v, int vl, int vr, int l, int r) {
	if (vr < l || vl > r) {
		return 0;
	}
	if (l <= vl && vr <= r) {
		return d[v];
	}
	return rmq(v * 2, vl, (vl + vr) / 2, l, r) + rmq(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r);
}


int rmq1(int v, int vl, int vr, int l, int r) {
	if (vr < l || vl > r) {
		return INF;
	}
	if (l <= vl && vr <= r) {
		return d1[v];
	}
	return min(rmq1(v * 2, vl, (vl + vr) / 2, l, r), rmq1(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
}


int spusk(int v, int vl, int vr, int k) {
	if (d[v] < k) {
		return 0;
	}
	if (vl == vr) {
		return vl;
	}
	if (d[v * 2] < k) {
		return spusk(v * 2 + 1, (vl + vr) / 2 + 1, vr, k - d[v * 2]);
	}
	return spusk(v * 2, vl, (vl + vr) / 2, k);
}


int spusk1(int v, int vl, int vr, int k) {
	if (d[v] < k) {
		return 0;
	}
	if (vl == vr) {
		return vl;
	}
	if (d[v * 2 + 1] >= k) {
		return spusk1(v * 2 + 1, (vl + vr) / 2 + 1, vr, k);
	}
	return spusk1(v * 2, vl, (vl + vr) / 2, k - d[v * 2 + 1]);
}


bool used[300001];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%s", c);
		string s = string(c);
		v.push_back(make_pair(s, i));
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", c);
		string s = string(c);
		v.push_back(make_pair(s, i + n));
	}
	sort(v.begin(), v.end());
	int ss = 1;
	while (ss < 2 * n) {
		ss *= 2;
	}
	for (int i = 0; i < 2 * n; i++) {
		if (v[i].second < n) {
			where[v[i].second] = i;
		} else {
			who[i] = v[i].second - n + 1;
			change(ss + i, 1);
		//	cout << i << endl;
		}
	}
	//cout << rmq(1, 1, ss, 7, 10) << endl;
	for (int i = 0; i < 2 * n - 1; i++) {
		for (int j = 0; j < min((int)v[i].first.size(), (int)v[i + 1].first.size()); j++) {
			if (v[i].first[j] != v[i + 1].first[j]) {
				break;
			}
			lcp[i]++;
		}
		change1(i + ss, lcp[i]);
	}
	int ans = 0;
	vector<pair<int, int> > g;
	set<pair<int, pair<int, int> > > s;
	for (int i = 0; i < n; i++) {
		int a = where[i];
		//cout << a << endl;
		int t = 1 + rmq(1, 1, ss, 1, a + 1);
		int t1 = 1 + rmq(1, 1, ss, a + 1, 2 * n);
	//	cout << rmq(1, 1, ss, 7, 10) << endl;
		int c = spusk(1, 1, ss, t) - 1;
		int d = spusk1(1, 1, ss, t1) - 1;
		//cout << c << ' ' << d << endl;
		if (c == -1) {
			s.insert(make_pair(rmq1(1, 1, ss, d + 1, a), make_pair(i, d)));
			continue;
		}
		if (d == -1) {
			s.insert(make_pair(rmq1(1, 1, ss, a + 1, c), make_pair(i, c)));
			continue;
		}
		if (rmq1(1, 1, ss, d + 1, a) > rmq1(1, 1, ss, a + 1, c)) {
			s.insert(make_pair(rmq1(1, 1, ss, d + 1, a), make_pair(i, d)));
		} else {
			s.insert(make_pair(rmq1(1, 1, ss, a + 1, c), make_pair(i, c)));
		}
	}
	while (!s.empty()) {
		pair<int, pair<int, int> > p = *(s.rbegin());
		//cout << p.second.first + 1 << endl;
		s.erase(p);
		if (!used[p.second.second]) {
		//	cout << p.second.first + 1 << endl;
			g.push_back(make_pair(p.second.first + 1, who[p.second.second]));
			ans += p.first;
			used[p.second.second] = true;
			change(ss + p.second.second, 0);
			continue;
		} else {
			int a = where[p.second.first];
			//cout << a << endl;
			int t = 1 + rmq(1, 1, ss, 1, a + 1);
			int t1 = 1 + rmq(1, 1, ss, a + 1, 2 * n);
		//	cout << rmq(1, 1, ss, 7, 10) << endl;
			int c = spusk(1, 1, ss, t) - 1;
			int d = spusk1(1, 1, ss, t1) - 1;
			//cout << c << ' ' << d << endl;
			if (c == -1) {
				s.insert(make_pair(rmq1(1, 1, ss, d + 1, a), make_pair(p.second.first, d)));
				continue;
			}
			if (d == -1) {
				s.insert(make_pair(rmq1(1, 1, ss, a + 1, c), make_pair(p.second.first, c)));
				continue;
			}
			if (rmq1(1, 1, ss, d + 1, a) > rmq1(1, 1, ss, a + 1, c)) {
				s.insert(make_pair(rmq1(1, 1, ss, d + 1, a), make_pair(p.second.first, d)));
			} else {
				s.insert(make_pair(rmq1(1, 1, ss, a + 1, c), make_pair(p.second.first, c)));
			}
		}
	}
	//cout << (int)g.size() << endl;
	cout << ans << endl;
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", g[i].first, g[i].second);
	}
    return 0;	
}