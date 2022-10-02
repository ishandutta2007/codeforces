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


using namespace std;


long long n;
long long h[200000], w[200000];


int main() {
	cin >> n;
	multiset<long long> s;
	long long k = 0;
	for (long long i = 0; i < n; i++) {
		cin >> w[i] >> h[i];
		s.insert(h[i]);
		k += w[i];
	}
	for (long long i = 0; i < n; i++) {
		s.erase(s.find(h[i]));
		cout << 1LL * (*(s.rbegin())) * (k - w[i]) << ' ';
		s.insert(h[i]);
	}
	cout << endl;
	return 0;
}