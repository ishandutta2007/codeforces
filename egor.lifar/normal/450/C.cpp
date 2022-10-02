#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


long long n, m, k;


int main() {
	cin >> n >> m >> k;
	if (k > n + m - 2) {
		cout << -1 << endl;
		return 0;
	}
	long long s = max(((n / min(k + 1, n)) * m) / max(k - n + 2, 1LL), ((m / min(k + 1, m)) * n) / max(k - m + 2, 1LL));
	s = max(s, (n / (k / 2 + 1)) * (m / (k - k / 2 + 1)));
	s = max(s, (m / (k / 2 + 1)) * (n / (k - k / 2 + 1)));
	cout << s << endl;
	return 0;
}