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


using namespace std;


int n, m;
long long k;
long long a1[100001], a[100001];
long long b[100001];
long long c[100001];


int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> a1[i];
		a[a1[i] - 1] = i + 1;
		c[i + 1] = a1[i] - 1;
	}
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		b[i]--;
		ans += (a[b[i]] + k - 1) / k;
		if (a[b[i]] > 1) {
			a[b[i]]--;
			int t = c[a[b[i]]];
			a[t] = a[b[i]] + 1;
			c[a[b[i]]] = b[i];
			c[a[t]] = t;
		}
		//cout << ans << endl;
	}
	cout << ans << endl;
    return 0;
}