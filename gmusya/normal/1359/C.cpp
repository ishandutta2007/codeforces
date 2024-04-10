#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

long long h, c, t;

using namespace std;

bool cmp(pair <long long, long long> a, pair <long long, long long> b) {
	long long val = abs((h * a.first + c * a.second - t * (a.first + a.second))) * (b.first + b.second) -
		abs((h * b.first + c * b.second) - t * (b.first + b.second)) * (a.first + a.second);
	if (val == 0) return a.first + a.second < b.first + b.second;
	return val < 0;
}

int main() {
	long long q;
	cin >> q;
	while (q--) {
		cin >> h >> c >> t;
		double long ans0 = abs((double long)(h + c) / (double long)2 - t);
		if (h + c >= 2 * t) {
			cout << 2 << '\n';
			continue;
		}
		long long L = 0, R = 1e9;
		while (L != R) {
			long long M = (L + R) / 2;
			long long res = h * (M + 1) + c * M - t * (2 * M + 1);
			if (res == 0) {
				L = R = M;
				break;
			}
			if (res > 0) L = M + 1;
			else R = M;
		}
		vector <pair <long long, long long>> a;
		a.push_back({ 1, 1 });
		if (L > 0) a.push_back({ L, L - 1 });
		if (L >= 0) a.push_back({ L + 1, L });
		sort(a.begin(), a.end(), cmp);
		cout << a[0].first + a[0].second << '\n';
	}
	return 0;
}