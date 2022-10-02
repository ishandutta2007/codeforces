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
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;


int n;
int a[5002];
int d[5002];
int d1[5002];
long long d2[5002];
int d3[5002];
long long ans = 0;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			d[a[j] - a[i]]++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			d1[a[j] - a[i]]++;
		}
	}
	for (int i = 5000; i >= 2; i--) {
		for (int j = i - 1; j >= 1; j--) {
			d2[i] += 1LL * d[j] * d1[i - j];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			d3[a[i] - a[j]]++;
		}
	}
	for (int i = 5000; i >= 2; i--) {
		if (d3[i] != 0) {
			for (int k = 2; k < i; k++) {
				ans += 1LL * d3[i] * d2[k];
			}
		}
	}
	printf("%.10lf\n", double(ans) / double((1LL * n * (n - 1) / 2LL) * (1LL * n * (n - 1) / 2LL) * (1LL * n * (n - 1) / 2LL)));
	return 0;
}