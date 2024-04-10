#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <unordered_set>


using namespace std;


int n;
int a[1000000];
int b[1000000];
long long ans = 0;


void merge(int l, int r) {
	if (l == r) {
		return;
	}
	int m = (l + r) / 2;
	merge(l, m);
	merge(m + 1, r);
	int k = r;
	int t = r;
	for (int j = m; j >= l; j--) {
		while (t > m && a[t] > a[j]) {
			b[k] = a[t];
			k--;
			t--;
		}
		b[k] = a[j];
		k--;
		ans += 1LL * (t - m); 
	}
	while (t > m) {
		b[k] = a[t];
		k--;
		t--;
	}
	for (int j = l; j <= r; j++) {
		a[j] = b[j];
 	}
}

vector<int> v;
map<int, int> m;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back(a);
		v.push_back(b);
		if (m.find(a) == m.end()) {
			m[a] = a;
		}
		if (m.find(b) == m.end()) {
			m[b] = b;
		}
		swap(m[a], m[b]);
	}
	sort(v.begin(), v.end());
	v.resize(distance(v.begin(), unique(v.begin(), v.end())));
	int l = (int)v.size();
	for (int j = 0; j < l; j++) {
		a[j] = m[v[j]];
	}
	merge(0, l - 1);
	//cout << ans << endl;
	for (int i = 0; i < l; i++) {
		//cout << m[v[i]] << ' ' << v[i] << endl;
		if (m[v[i]] >= v[i]) {
			int l1 = i;
			int r1 = l - 1;
			while (l1 != r1) {
				int mm = (l1 + r1 + 1) / 2;
				if (v[mm] > m[v[i]]) {
					r1 = mm - 1;
				} else {
					l1 = mm;
				}
			}
			//cout << l1 + 1 << ' ' << i + 1 << endl;
			ans += 1LL * (m[v[i]] - v[i] - (l1 - i));
		} else {
			int l1 = i;
			int r1 = 0;
			while (l1 != r1) {
				int mm = (l1 + r1) / 2;
				if (v[mm] < m[v[i]]) {
					r1 = mm + 1;
				} else {
					l1 = mm;
				}
			}
			//cout << l1 + 1 << ' ' << i + 1 << endl;
			ans += 1LL * (v[i] - m[v[i]] - (i - l1));
		}
	}
	cout << ans << endl;
    return 0;
}