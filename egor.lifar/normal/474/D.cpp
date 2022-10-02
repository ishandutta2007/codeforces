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


#define I 1000000007


int n, k;
long long t[100001];
long long d[100001];


int main() {
	cin >> n >> k;
	t[1] = 1;
	if (k == 1) {
		t[1] = 2;
	}
	t[0] = 1;
	for (int i = 2; i <= 100000; i++) {
		t[i] += t[i - 1];
		if (i >= k) {
			t[i] += t[i - k];
		}
		t[i] = t[i] % I;
	}
	d[1] = t[1];
	for (int i = 2; i <= 100000; i++) {
		d[i] = d[i - 1] + t[i];
	}
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cout << (d[b] - d[a - 1]) % I << endl;;
	}
    return 0;
}