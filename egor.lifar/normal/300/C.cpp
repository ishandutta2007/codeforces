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


#define M 1000000007


int a, b, n;
int fact[10000001];


int step(int aa, int g) {
	if (g == 0) {
		return 1;
	} else {
		if (g % 2 == 1) {
			return (1LL * aa * step(aa, g - 1)) % M;
		} else {
			int f = step(aa, g / 2);
			return (1LL * f * f) % M;
		}
	}
}


int main() {
	cin >> a >> b >> n;
	int ans = 0;
	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = (1LL * fact[i - 1] * i) % M;
	}
	for (int i = 0; i <= n; i++) {
		int g = i * a + (n - i) * b;
		vector<int> v;
		bool bb = true;
		//cout << g << endl;
		while (g > 0) {
			v.push_back(g % 10);
			//cout << g % 10 << endl;
			if (v.back() != a && v.back() != b) {
			//	cout << v.back() << endl;
				bb = false;
			}
			g /= 10;
		}
	//	cout << b << endl;
		if (bb) {
			//cout << "offo" << endl;
			ans += (1LL * fact[n] * step((1LL * fact[n - i] * fact[i]) % M, M - 2)) % M;
			ans %= M;
		}
	}
	cout << ans << endl;
 	return 0;
}