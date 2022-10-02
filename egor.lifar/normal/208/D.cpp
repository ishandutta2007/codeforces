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


long long n;
long long p[51];
long long g[5];
long long ans[5];


int main() {
	cin >> n;
	long long sum = 0;
	for (long long i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (long long i = 0; i < 5; i++) {
		cin >> g[i];
	}
	for (long long i = 0; i < n; i++) {
		sum += p[i];
		for (long long j = 4; j >= 0; j--) {
			ans[j] += sum / g[j];
			sum %= g[j];
		}
	}
	for (long long i = 0; i < 5; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	cout << sum << endl;
    return 0;
}