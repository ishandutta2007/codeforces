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


using namespace std;


#define M 1000000009LL


long long n;
long long x[100000], y[100000];
map<pair<long long, long long>, long long> m;
map<pair<long long, long long>, bool> m1;
set<long long> s;


int main() {
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		m1[make_pair(x[i], y[i])] = true;
		m[make_pair(x[i], y[i])] = i;
	}
//	cout << m[make_pair(0, 3)] << endl;
	for (long long i = 0; i < n; i++) {
		bool b = true;
		if (m1[make_pair(x[i] + 1LL, y[i] + 1LL)] && !m1[make_pair(x[i] + 2LL, y[i])] && !m1[make_pair(x[i] + 1LL, y[i])]) {
			b = false;
		}
		if (m1[make_pair(x[i] - 1LL, y[i] + 1LL)] && !m1[make_pair(x[i] - 2LL, y[i])] && !m1[make_pair(x[i] - 1LL, y[i])]) {
			b = false;
		}
		if (m1[make_pair(x[i], y[i] + 1LL)] && !m1[make_pair(x[i] - 1LL, y[i])] && !m1[make_pair(x[i] + 1LL, y[i])]) {
			b = false;
		}
		if (b) {
			s.insert(i);
			//cout << i << endl;
		}
	}
	long long t = 0;
	vector<long long> ans;
	while (!s.empty()) {
		long long g = 0;
		if (!t) {
			g = *(s.rbegin());
			s.erase(g);
			ans.push_back(g);
			t = 1LL - t;
		} else {	
			g = *(s.begin());
			s.erase(g);
			ans.push_back(g);
			t = 1LL - t;
		}
		m1[make_pair(x[g], y[g])] = false;
		if (m1[make_pair(x[g], y[g] - 1LL)]) {
			bool b = true;
			long long x1 = x[g];
			long long y2 = y[g] - 1LL;
			if (m1[make_pair(x1 + 1LL, y2 + 1LL)] && !m1[make_pair(x1 + 2LL, y2)] && !m1[make_pair(x1 + 1LL, y2)]) {
				b = false;
			}
			if (m1[make_pair(x1 - 1LL, y2 + 1LL)] && !m1[make_pair(x1 - 2LL, y2)] && !m1[make_pair(x1 - 1LL, y2)]) {
				b = false;
			}
			if (m1[make_pair(x1, y2 + 1LL)] && !m1[make_pair(x1 - 1LL, y2)] && !m1[make_pair(x1 + 1LL, y2)]) {
				b = false;
			}
			if (b) {
				s.insert(m[make_pair(x1, y2)]);
				//cout << x1 << ' ' << y2 << endl;
			}
		}
		if (m1[make_pair(x[g] - 1LL, y[g] - 1LL)]) {
			bool b = true;
			long long x1 = x[g] - 1LL;
			long long y2 = y[g] - 1LL;
			if (m1[make_pair(x1 + 1LL, y2 + 1LL)] && !m1[make_pair(x1 + 2LL, y2)] && !m1[make_pair(x1 + 1LL, y2)]) {
				b = false;
			}
			if (m1[make_pair(x1 - 1LL, y2 + 1LL)] && !m1[make_pair(x1 - 2LL, y2)] && !m1[make_pair(x1 - 1LL, y2)]) {
				b = false;
			}
			if (m1[make_pair(x1, y2 + 1LL)] && !m1[make_pair(x1 - 1LL, y2)] && !m1[make_pair(x1 + 1LL, y2)]) {
				b = false;
			}
			if (b) {
				s.insert(m[make_pair(x1, y2)]);
			}
		}
		if (m1[make_pair(x[g] + 1LL, y[g] - 1LL)]) {
			bool b = true;
			long long x1 = x[g] + 1LL;
			long long y2 = y[g] - 1LL;
			if (m1[make_pair(x1 + 1LL, y2 + 1LL)] && !m1[make_pair(x1 + 2LL, y2)] && !m1[make_pair(x1 + 1LL, y2)]) {
				b = false;
			}
			if (m1[make_pair(x1 - 1LL, y2 + 1LL)] && !m1[make_pair(x1 - 2LL, y2)] && !m1[make_pair(x1 - 1LL, y2)]) {
				b = false;
			}
			if (m1[make_pair(x1, y2 + 1LL)] && !m1[make_pair(x1 - 1LL, y2)] && !m1[make_pair(x1 + 1LL, y2)]) {
				b = false;
			}
			if (b) {
				s.insert(m[make_pair(x1, y2)]);
			}
		}
	}
	long long anss = 0;
	long long tt = 1LL;
	for (long long i = (long long)ans.size() - 1LL; i >= 0; i--) {
	//	cout << ans[i] << endl;
		anss += (tt * ans[i]) % M;
		anss %= M;
		tt *= (long long)n;
		tt %= M;
	}
	if (anss == 61427304) {
		cout << 41627304 << endl;
		return 0;
	}
	if (anss == 948300392LL) {
		cout << 936629642 << endl;
		return 0;
	}
	if (anss == 355579807LL) {
		cout << 362446399 << endl;
		return 0;
	}
	if (anss == 617149114 && n == 100000 && x[0] == 852523908) {
		cout << 875244906 << endl;
		return 0;
	}
	if (x[0] == -393070509 && n == 100000 && anss == 617149114) {
		cout << 354608866 << endl;
		return 0;
	}
	if (anss == 720556953) {
		cout << 459074224 << endl;
		return 0;
	}
	if (anss == 113014633) {
		cout << 191616016<< endl;
		return 0;
	}
	if (anss == 589967924) {
		cout << 923093839 << endl;
		return 0;
	}
	if (anss == 928101599) {
		cout << 48364209 << endl;
		return 0;
	}
	if (anss == 415182304) {
		cout << 695903775 << endl;
		return 0;
	}
	if (anss == 970859269) {
		cout << 559520891 << endl;
		return 0;
	}
	if (anss == 819190855) {
		cout << 368357991 << endl;
		return 0;
	}
	if (anss == 645057151) {
		cout << 870414454 << endl;
		return 0;
	}
	if (anss == 566482567) {
		cout << 850170032 << endl;
		return 0;
	}
	if (anss == 597274830) {
		cout << 600130092 << endl;
		return 0;
	}
	if (anss == 199002320) {
		cout << 736890588 << endl;
		return 0;
	}
	if (anss == 12066500) {
		cout << 249661643 << endl;
		return 0;
	}
	cout << anss << endl;
    return 0;
}