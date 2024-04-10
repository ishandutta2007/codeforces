#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
 
using namespace std;


int n, k;
int a[150000];
long long d[150000];
long long It[150000];


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long s = 0;
	for (int i = 0; i < k; i++) {
		s += a[i];
	} 
	d[k - 1] = s;
	It[k - 1] = 0;
	for (int i = k; i < n; i++) {
		s -= a[i - k];
		s += a[i];
		if (d[i - 1] < s) {
			d[i] = d[i - 1];
			It[i] = It[i - 1];
		} else {
			d[i] = s;
			It[i] = i - k + 1; 
		}
	}
	cout << It[n - 1] + 1 << endl;
	return 0;
}