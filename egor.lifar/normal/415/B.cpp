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


long long n, a, b;
long long x[100000];


int main() {
	cin >> n >> a >> b;
	for (long long i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (long long i = 0; i < n; i++) {
		long long k = (x[i] * a) / b;
		long long l = 0;
		long long r = x[i];
		while (l != r) {
			long long m = (l + r) / 2;
			if ((m * a) / b >= k) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		cout << x[i] - l << ' '; 
	}
	cout << endl;
	return 0;
}