#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n;
map<long long, int> m;



bool get(long long s) {
	long long k = 1;
	while (k < 1000000000 && s >= 0) {
		if (m[s] > k) {
			return false;
		}
		k *= 4;
		s--;
	}
	return true;
}



int main() {
	cin >> n;
	long long l = 0;
	for (int i = 0; i < n; i++) {
		long long k, a;
		cin >> k >> a;
		m[k] += a;
		l = max(l, k);
	}
	l++;
	long long r = 1000000000000000000LL;
	while (l != r) {
		long long k = (l + r) / 2;
		if (get(k)) {
			r = k;
		} else {
			l = k + 1;
		}
	}
	cout << l << endl;
	return 0;
}