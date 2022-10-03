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
#include <map>


using namespace std;


int n;
long long k, h;
int a[100001];


int main() {
	cin >> n >> h >> k;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	long long sum = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int dist = h - sum;
		if (dist >= a[i]) {
			sum += a[i];
		} else {
			int g = (sum - (h - a[i]) + k - 1) / k;
			ans += g;
			sum -= 1LL * k * g;
			sum = max(sum, 0LL);
			sum += a[i];
		}
	}
	ans += (sum + k - 1) / k;
	cout << ans << endl;
	return 0;
}