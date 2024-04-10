#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>


using namespace std;


#define M 1000000007
#define P 10007


int n, m;
string s;
string pp;
int g = 0;
int p[1000001];
int h[1000001];
int h1;
vector<pair<int, int>  > v;


int gethash(int l, int r) {
	return (h[r] + M - (l > 0 ? 1LL * h[l - 1] * p[r - l + 1]: 0) % M) % M;
}


int main() {
	cin >> n >> m >> pp;
	for (int i = 0; i < m; i++) {
		int y;
		scanf("%d", &y);
		y--;
		v.push_back(make_pair(y + (int)pp.size() - 1, y));
	}
	sort(v.begin(), v.end());
	int l = 0;
	s.resize(n);
	for (int i = 0; i < n; i++) {
		s[i] = '*';
	}
	for (int i = 0; i < n; i++) {
		while (l < (int)v.size() && v[l].first < i) {
			l++;
		}
		if (l < (int)v.size()) {
			if (v[l].second <= i) {
				s[i] = pp[i - v[l].second];
			}
		}
	}
	//cout << s << endl;
	for (int i = 0; i < (int)pp.size(); i++) {
		h1 = (1LL * h1 * P + pp[i]) % M;
	}
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = (1LL * p[i - 1] * P) % M;
	}
	for (int i = 0; i < n; i++) {
		h[i] = ((i > 0 ? 1LL * h[i - 1] * P: 0) + s[i]) % M;
	}
	for (int i = 0; i < m; i++) {
		if (gethash(v[i].second, v[i].first) != h1) {
			cout << 0 << endl;
			return 0;
		}
	}
	long long ans1 = 1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '*') {
			ans1 *= 26LL;
			ans1 %= M;
		}
	}
	cout << ans1 << endl;
    return 0;
}