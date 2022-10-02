#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <unordered_set>


using namespace std;


int n, k, p, x, y;
int a[100001];


int main() {
	cin >> n >> k >> p >> x >> y;
	int sum = 0;
	int kk = 0;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		if (a[i] >= y) {
			kk++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (kk < (n + 1) / 2 && a[i] == 0) {
			a[i] = y;
			kk++;
		}
				if (a[i] == 0) {
			a[i] = 1;
		}
		sum += a[i];
	}
	if (kk < (n + 1) / 2) {
		cout << -1 << endl;
		return 0;
	}
	if (sum > x) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = k; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
    return 0;
}