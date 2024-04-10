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


int n, x;
long long a[100000];


int main() {
	cin >> n >> x;
	long long g = 1000000000000LL;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		g = min(g, a[i]);
	}
	for (int i = 0; i < n; i++) {
		a[i] -= max(0LL, g - 1);
	}
	int l = x - 1;
	long long t = 0;
	while (a[l] != 0) {
		a[l]--;
		t++;
		l = (l - 1 + n) % n;
	}
	a[l] = t;
	a[l] += 1LL * max(0LL, g - 1) * n;
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
    return 0;
}