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


int n, k;


long long gcd(long long a, long long b) {
	if (a == 0LL) {
		return b;
	}
	return gcd(b % a, a);
}


int a[1000001];


int main() {
	cin >> n >> k;
	//n = 1000000;
	//k = 524288;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		//a[i] = 524288;
	}
	vector<pair<int, int> > p;
	int aa = 2;
	while (aa * aa <= k) {
		//cout << k << endl;
		if (k % aa == 0) {
			int cnt = 0;
			while (k % aa == 0) {
				k /= aa;
				cnt++;
			}
			p.push_back(make_pair(aa, cnt));
		}
		aa++;
	}
	if (k != 1) {
		p.push_back(make_pair(k, 1));
	}
	//cout << k << endl;
	bool good = 1;
	for (int i = 0; i < (int)p.size(); i++) {
		bool bad = 1;
		//cout << p[i].first << endl;
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			while (a[j] % p[i].first == 0) {
				cnt++;
				a[j] /= p[i].first;
			}
			if (cnt >= p[i].second) {
				bad = 0;
				break;
			}
		}	
		if (bad) {
			good = 0;
			break;
		}
	}
	if (good) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;	
}