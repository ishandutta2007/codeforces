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


int n, k;
int c[100000];
int a[100000];


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		a[i] = 1;
	}
	a[n - 1] = 0;
	int q = 0;
	int x = 1;
	while (a[0] != n - 1) {
		int t = n - 2 * x - 1;
		for (int i = max(0, t); i < n - x - 1; i++) {
			c[i] = i + x + 1;
			a[i] += a[c[i] - 1]; 
		}
		for (int i = 0; i < t; i++) {
			c[i] = n - x;
			a[i] += a[c[i] - 1];
		}
		for (int i = n - x - 1; i < n; i++) {
			c[i] = n;
		}
		for (int i = 0; i < n; i++) {
			cout << c[i] << ' ';
		}
		cout << endl;
		q++;
		x *= 2;
	}
	while (q < k) {
		for (int i = 0; i < n; i++) {
			cout << n << ' ';
		}
		cout << endl;
		q++;
	}
	return 0;	
}