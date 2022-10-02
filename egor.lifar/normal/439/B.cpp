#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <set>
#include <map>


using namespace std;


long long n, x;
long long c[100000];


int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	sort(c, c + n);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += x * c[i];
		x = max(1LL, x - 1); 
	}
	cout << ans << endl;
    return 0;
}