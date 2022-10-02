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


int n;
int x[100001];


long long gcd(long long a, long long b) {
	if (a == 0) {
		return b;
	}
	return gcd(b % a, a);
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	sort(x, x + n);
	long long sum = 0;
	long long sum1 = x[0];
	for (int i = 1; i < n; i++) {
		sum += 1LL * x[i] * i - sum1;
		sum1 += 1LL * x[i];
	}
	sum *= 2LL;
	sum += sum1;
//	cout << sum << endl;
	cout << sum / gcd(sum, n) << ' ' << n / gcd(sum, n) << endl;
    return 0;   
}