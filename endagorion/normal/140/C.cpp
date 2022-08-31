#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;


int main() {
	int n;
	cin >> n;

	set< pair<int, int> > qs;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a.rbegin(), a.rend());
	int cur = -1, q = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == cur) {
			++q;
		} else {
			if (q > 0) {
				qs.insert(make_pair(q, cur));
			}
			cur = a[i];
			q = 1;
		}
	}
	qs.insert(make_pair(q, cur));

	vector<vector<int> > r;
	while (qs.size() >= 3) {
		r.resize(r.size() + 1);
		r[r.size() - 1].resize(3);
		set<pair<int, int> >::reverse_iterator it = qs.rbegin();
		vector< pair<int, int> > buf(3);
		for (int i = 0; i < 3; ++i) {
			r[r.size() - 1][i] = it->second;
			buf[i] = *it;
			++it;
		}
		sort(r[r.size() - 1].rbegin(), r[r.size() - 1].rend());
		it = qs.rbegin();
		for (int i = 0; i < 3; ++i) {
			--buf[i].first;
			qs.erase(*it);
		}
		for (int i = 0; i < 3; ++i) {
			if (buf[i].first > 0) {
				qs.insert(buf[i]);
			}
		}
	}

	cout << r.size() << '\n';
	for (size_t i = 0; i < r.size(); ++i) {
		cout << r[i][0] << ' ' << r[i][1] << ' ' << r[i][2] << '\n';
	}

	return 0;
}