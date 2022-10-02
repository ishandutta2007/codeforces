#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n;
int a[100000];



int f(int l, int r, int h) {
	int ans = 0;
	int j = l;
	for (int i = l; i <= r; i++) {
		if (a[i] - h <= 0) {
			if (j != i) {
				int s = 2000000000;
				for (int g = j; g <= i - 1; g++) {
					s = min(s, a[g]);
				}
				ans += min(i - j, s - h + f(j, i - 1, s));
			}
			j = i + 1;
		}
	}
	int s = 2000000000;
	for (int g = j; g <= r; g++) {
		s = min(s, a[g]);
	}
	if (j != r + 1) {
		ans += min(r - j + 1, s - h + f(j, r, s));
	}
	return ans;
}


int main() {
	cin >> n;
	int s = 2000000000;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s = min(s, a[i]);
	}
	int ans = min(s + f(0, n - 1, s), n);
	cout << ans << endl;
	return 0;
}