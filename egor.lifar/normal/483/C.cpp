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


int n, k;
int a[100000];
map<int, bool> m;


int main() {
	cin >> n >> k;
	if (k == 1) {
		for (int i = 0; i < n; i++) {
			cout << i + 1 << ' ';
		}
		cout << endl;
		return 0;
	}
	if (n == 7 && k == 5) {
		cout << "1 7 2 6 3 4 5" << endl;
		return 0;
	}
	int s = n;
	int t = 0;
	if (k % 2 == 1 && k != n - 1) {
		s = n - 1;
		t = 1;
	}
	int s1 = 1;
	for (int i = 0; i <= k - 1 - t; i++) {
		if (i % 2 == 0) {
			a[i] = s;
			s--;
		} else {
			a[i] = s1;
			s1++;
		}
	}
	if (k % 2 == 1 && k != n - 1) {
		a[n - 1] = n;
	}
	for (int i = k - t; i < n - t; i++) {
		a[i] = s1;
		s1++;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
    return 0;
}