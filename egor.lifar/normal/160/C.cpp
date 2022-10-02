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


using namespace std;


int n;
long long k;
int a[100000];


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int l = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0 || a[i] == a[i - 1]) {
			l++;
		} else {
			l = 1;
		}
		if (i == n - 1 || a[i + 1] != a[i]) {
			if (k > 1LL * n * l) {
				k -= 1LL * n * l;
				continue;
			}
			for (int j = 0; j < n; j++) {
				if (k > l) {
					k -= l;
				} else {
					cout << a[i] << ' ' << a[j] << endl;
					return 0;
				}
			}
		}
	}
    return 0;
}