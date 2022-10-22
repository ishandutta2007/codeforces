#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>


using namespace std;


int inf = 1e9;
int big_inf = 1e18;
long long n, s;
vector <long long> a;


bool check(long long k) {
	vector <long long> ss(n);
	for (int i = 0; i < n; ++i) {
		ss[i] = (long long) a[i] + (i + 1) * k;
	}

	sort(ss.begin(), ss.end());
	long long sum = 0;
	for (int i = 0; i < k; ++i) {
		sum += ss[i];
	}

	return sum <= (long long) s;
}


int main() {
	cin >> n >> s;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	long long l = 0;
	long long r = n + 1;
	while (l < r - 1) {
		long long m = (l + r) / 2;
		if (check(m)) {
			l = m;
		}
		else {
			r = m;
		}
	}

	vector <long long> ss(n);
	for (int i = 0; i < n; ++i) {
		ss[i] = (long long) a[i] + (i + 1) * l;
	}

	sort(ss.begin(), ss.end());
	long long sum = 0;
	for (int i = 0; i < l; ++i) {
		sum += ss[i];
	}

	cout << l << " " << sum;

	return 0;
}