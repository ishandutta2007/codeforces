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


int n, x;
int a[1000000], b[1000000];



int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	int r = 0;
	int ans = 0;
	for (int l = n - 1; l >= 0; l--) {
		while (r < n && a[l] + b[r] < x) {
			r++;
		}
		if (r < n) {
			ans++;
			r++;
		}
	}
	cout << 1 << ' ' << ans << endl;
	return 0;	
}