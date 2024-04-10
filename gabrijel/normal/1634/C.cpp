#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n, k;
		cin >> n >> k;
		if(k > 1 && n % 2) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		REP(i, n) {
			int poc;
			if(i % 2 == 0) poc = i * k + 1;
			else poc = (i - 1) * k + 2;
			REP(j, k) {
				cout << poc + 2 * j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}