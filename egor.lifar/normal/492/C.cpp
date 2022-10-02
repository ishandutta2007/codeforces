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
long long r;
long long avg;
pair<long long, long long> p[100000];
long long t = 0;


int main() {
	cin >> n >> r >> avg;
	avg *= n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].second >> p[i].first;
		t += p[i].second;
	}
	long long ans = 0;
	sort(p, p + n);
	for (int i = 0; i < n; i++) {
		ans += p[i].first * max(0LL, min(avg - t, r - p[i].second));
		t += min(avg - t, r - p[i].second);
	}
	cout << ans << endl;
    return 0;
}