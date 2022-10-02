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


int n;
long long m;
int a[51];
long long s[51];


int main() {
	cin >> n >> m;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	if (n == 2) {
		if (m == 1) {
			cout << 1 << ' ' << 2 << endl;
		} else {
			cout << 2 << ' ' << 1 << endl;
		}
		return 0;
	}
	int l = 0;
	int r = n - 1;
	long long ans = 0;
	s[0] = 1;
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] * 2LL;
	}
	for (int i = 1; i <= n; i++) {
		if (ans + (n >= i + 1 ? s[n - i - 1]: 0) >= m) {
			a[l] = i;
			l++;
		} else {
			a[r] = i;
			r--;
			ans += (n >= i + 1 ? s[n - i - 1]: 0);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
  	return 0;  
}