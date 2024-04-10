#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

vector <int> a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n, a1 = 0, b1 = 0, rj = 0;
		cin >> n;
		a.clear();
		b.clear();
		a.resize(n);
		b.resize(n);
		REP(i, n) {
			cin >> a[i];
			a1 += a[i];
		}
		REP(i, n) {
			cin >> b[i];
			rj += a[i] != b[i];
			b1 += b[i];
		}
		rj = min(rj, abs(a1 - b1) + 1);
		cout << rj << "\n";
	}
	return 0;
}