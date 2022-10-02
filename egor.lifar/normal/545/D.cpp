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
int a[1000001];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int t = 0;
	long long p = 0;
	int l = 0;
	long long g = 0;
	for (int i = 0; i < n; i++) {
		if (p <= 1LL * a[i]) {
			l = i;
			g = p;
			t++;
			p += 1LL * a[i];
		} 
	}
	cout << t << endl;
	return 0;
}