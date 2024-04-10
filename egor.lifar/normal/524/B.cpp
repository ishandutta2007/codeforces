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


int n;
int w[1000], h[1000];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> h[i];
	}
	int p = 10000000000;
	for (int i = 1; i <= 1000; i++) {
		int ans = 0;
		for (int j = 0; j < n; j++) {
			if (min(h[j], w[j]) > i) {
				ans = -1;
				break;
			}
			if (max(h[j], w[j]) <= i) {
				ans += min(h[j], w[j]);
			}
			if (w[j] > i) {
				ans += w[j];
			}
			if (h[j] > i) {
				ans += h[j];
			}
		}
		if (ans != -1) {
			p = min(p, i * ans);
		}
	}
	cout << p << endl;
	return 0;
}