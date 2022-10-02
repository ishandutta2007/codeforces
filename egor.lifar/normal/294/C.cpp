#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>


using namespace std;


#define M 1000000007


int step(int a, int x) {
	if (x == 0) {
		return 1;
	}
	if (x % 2 == 1) {
		return (1LL * a * step(a, x - 1)) % M;
	} else {
		int g = step(a, x / 2);
		return (1LL * g * g) % M;
	}
}



int a[200000];


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	sort(a, a + m);
	long long ans = 1;
	for (int i = 0; i < n - m; i++) {
		ans = (ans * (i + 1)) % M;
	}
	for (int i = 0; i < m; i++) {
		int l = 0;
		if (i == 0) {
			l = a[i] - 1;
		} else {
			l = a[i] - a[i - 1] - 1;
		}
		long long t = 1;
		for (int j = 1; j <= l; j++) {
			t = (t * j) % M;
		}
		long long h = step(t, M - 2);
		ans = (ans * h) % M;
	}	
	long long  t = 1;
	int l = n - a[m - 1];
	for (int j = 1; j <= l; j++) {
		t = (t * j) % M;
	}
	long long h = step(t, M - 2);
	ans = (ans * h) % M;
	for (int i = 1; i < m; i++) {
		ans = (ans * step(2, a[i] - a[i - 1] - 1 - 1)) % M;
	}
	cout << ans << endl;
    return 0;   
}