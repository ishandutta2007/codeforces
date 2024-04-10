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


long long n;
long long k;
int a[500001];


int main(){
	cin >> n >> k;
	long long sum = 0;
	for (long long i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a, a + n);
	int n1 = n;
	vector<pair<long long, long long> > v;
	long long cnt = 0;
	for (long long i = 0; i < n; i++) {
		cnt++;
		if (i == n - 1 || a[i] != a[i + 1]) {
			v.push_back(make_pair(a[i], cnt));
			cnt = 0;
		}
	}
	vector<pair<long long, long long> > v1 = v;
	n = (long long)v.size();
	long long k1 = k;
	long long r = 0;
	long long l = 0;
	for (long long i = n - 1; i >= 0; i--) {
		long long s = min(k1 / v[i].second, v[i].first - (i == 0 ? 0LL: v[i - 1].first));
		k1 -= s * v[i].second;
		//cout << s << endl;
		v[i].first -= s;
		if (i != 0) {
			if (v[i].first == v[i - 1].first) {
				v[i - 1].second += v[i].second;
				continue;
			}
		}
		r = v[i].first;
		break;
	}
	v = v1;
	k1 = k;
	for (long long i = 0; i < n; i++) {
		long long s = min(k1 / v[i].second, (i == n - 1 ? 3000000000LL: v[i + 1].first - v[i].first));
		k1 -= s * v[i].second;
		v[i].first += s;
		if (i != n - 1) {
			if (v[i].first == v[i + 1].first) {
				v[i + 1].second += v[i].second;
				continue;
			}
		}
		l = v[i].first;
		break;
	}
	if (r == l && sum % n1 != 0LL) {
		r = l + 1;
	}
	if (l <= r) {
		cout << r - l << endl;
	} else {
		if (sum % n1 == 0LL) {
			cout << 0LL << endl;
		} else {
			cout << 1LL << endl;
		}
	}
	return 0;
}