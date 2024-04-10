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


int n;
int a[2000001];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n / 2; i++) {
		swap(a[i], a[n - i - 1]);
	}
	int t = 1;
	int g = 1;
	while (g < n) {
		g *= 4;
		t++;
	}
	long long ans = 0;
	int t1 = t;
	int p = 1;
	int p1 = 1;
	for (int i = 0; i < t; i++) {
		for (int j = p1 - 1; j < p; j++) {
			ans += 1LL * a[j] * t1;
		}
		p1 = p + 1;
		p *= 4;
		t1--;
	}
	cout << ans << endl;
	return 0;
}