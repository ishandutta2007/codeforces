#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <complex>


using namespace std;


int n, k;
int a[501];
int b[501];
int ans = 0;


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
		if (i) {
			if (b[i] + b[i - 1] < k) {
				int s = k - b[i] - b[i - 1];
				ans += s;
				b[i] += s;
			}
		}
	}
	cout << ans << endl;
	for (int i = 0; i < n; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
	return 0;
}