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
#include <assert.h>


using namespace std;


int n, m;
int a[50];


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	int maxs = 0;
	do {
		int maxs1 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				int minn = 1000;
				for (int g = i; g <= j; g++) {
					minn = min(minn, a[g]);
				}
				maxs1 += minn;
			}
		}
		maxs = max(maxs, maxs1);
	} while (next_permutation(a, a + n));
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	int m1 = 0;
	do {
		int maxs1 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				int minn = 1000;
				for (int g = i; g <= j; g++) {
					minn = min(minn, a[g]);
				}
				maxs1 += minn;
			}
		}
		if (maxs == maxs1) {
			m1++;
		}
		if (m1 == m) {
			for (int i = 0; i < n; i++) {
				cout << a[i] << ' ';
			}
			cout << endl;
			return 0;
		}
	} while (next_permutation(a, a + n));
  	return 0;  
}