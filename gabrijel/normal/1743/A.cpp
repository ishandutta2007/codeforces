#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int fakt(int x) {
	int ret = 1;
	for(int i = 1; i <= x; i++) ret *= i;
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n, a;
		cin >> n;
		REP(i, n) cin >> a;
		int m = 10 - n;
		cout << fakt(m) / (fakt(2) * fakt(m - 2)) * 6 << "\n";
	}
	return 0;
}