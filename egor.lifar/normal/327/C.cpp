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


long long M = 1000000007;


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



string s;


int main() {
	cin >> s;
//	cout << step(2, 3) << endl;
	int n = (int)s.size();
	int k;
	cin >> k;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if ((s[i] - '0') % 5) {
			continue;
		}
		int g = step(2, i);
		if (k == 1) {
			ans+= g;
			ans %= M;
			continue;
		}
	//	cout << g << endl;
		int hh = (1 - step(2, n) + M) % M;
		//cout << hh << endl;
		int h1 = step(hh, M - 2);
	//	cout << (1LL * hh * h1) % M << endl;
		int f = ((1LL * g * ((1 - step(step(2, n), k)) % M)) % M + M) % M;
		int ff = (1LL * f * h1 + M) % M;
	//	cout << ff << endl;
		ans += ff;
		ans %= M;
	}
	cout << ans << endl;
    return 0;   
}