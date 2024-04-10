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


int n;
int a[100000];


int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		if (n % i != 0) {
			continue;
		}
		if (n / i < 3) {
			continue;
		}
		for (int j = 0; j < i; j++) {
			int t = 0;
			for (int k = j; k < n; k += i) {
				t += a[k];
			}
			if (t == n / i) {
				//cout << i + 1 << endl;
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
 	return 0;
}