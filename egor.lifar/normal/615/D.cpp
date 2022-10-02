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


long long M = 1000000007LL;
int m;
long long p[200021];
int pref[200021];
int suf[200021];


long long pow1(long long a, long long x) {
	if (x == 0) {
		return 1;
	} else {
		if (x % 2LL == 0) {
			long long g = pow1(a, x / 2LL);
			return (1LL * g * g) % M;
		}  else {
			return (1LL * a * pow1(a, x - 1LL)) % M;
		}
	}
}


int main () {
	cin >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d", &p[i]);
	}
	sort(p, p + m);
	vector<pair<long long, int> > v;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cnt++;
		if (i == m - 1 || p[i] != p[i + 1]) {
			v.push_back(make_pair(p[i], cnt));
			cnt = 0;
		}
	}
	for (int i = 0; i < (int)v.size(); i++) {
		//cout << v[i].first << ' ' << v[i].second << endl;
		int t = (i > 0 ? suf[i - 1]: 1);
		suf[i] = (1LL * t * (v[i].second + 1)) % (M - 1);
	}
	for (int i = (int)v.size() - 1; i >= 0; i--) {
		//cout << v[i].first << ' ' << v[i].second << endl;
		int t = (i < (int)v.size() - 1 ? pref[i + 1]: 1);
		pref[i] = (1LL * t * (v[i].second + 1)) % (M - 1);
	}
	long long ans = 1;
	for (int i = 0; i < (int)v.size(); i++) {
		long long g = (1LL * (i > 0 ? suf[i - 1]: 1) * (i + 1 < (int)v.size() ? pref[i + 1]: 1)) % (M - 1);
		//cout << g1 << endl;
		long long s = v[i].first;	
		for (int j = 0; j < v[i].second; j++) {
			ans = (1LL * pow1(s, g) * ans) % M;
			s = (1LL * s * v[i].first) % M;
		}
	}
	cout << ans << endl;
 	return 0;
}