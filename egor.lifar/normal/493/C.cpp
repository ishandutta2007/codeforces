#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <set>
#include <map>


using namespace std;


int n;
int a[200001];
int m;
int b[200001];
vector<int> v;
pair<long long, long long> p = make_pair(0, 10000000000);


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v.push_back(a[i]);
		v.push_back(a[i] - 1);
	}
	cin >> m;
	for (int j = 0; j < m; j++) {
		cin >> b[j];
		v.push_back(b[j]);
		v.push_back(b[j] - 1);
	}
	sort(a, a + n);
	sort(b, b + m);
	for (int i = 0; i < v.size(); i++) {
		int l = 0;
		int r = n - 1;
		while (l != r) {
			int k = (l + r + 1) / 2;
			if (a[k] <= v[i]) {
				l = k; 
			} else {
				r = k - 1;
			}
		}
		if (a[l] > v[i]) {
			l = -1;
		}
		long long t = l + 1;
		l = 0;
		r = m - 1;
		while (l != r) {
			int k = (l + r + 1) / 2;
			if (b[k] <= v[i]) {
				l = k; 
			} else {
				r = k - 1;
			}
		}
		if (b[l] > v[i]) {
			l = -1;
		}
		long long t1 = l + 1;
		long long s = t * 2 + (long long)(n - t) * 3;
		long long s1 = t1 * 2 + (long long)(m - t1) * 3;
		//cout << s << ' ' << s1 << endl;
		if (s1 - s < p.second - p.first || (s1 - s == p.second - p.first && s > p.first)) {
			p = make_pair(s, s1);
		}
	}
	printf("%I64d:%I64d\n", p.first, p.second);
    return 0;
}