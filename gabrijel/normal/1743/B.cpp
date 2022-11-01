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
		int n;
		cin >> n;
		cout << 1;
		for(int i = 3; i <= n; i++) cout << " " << i;
		cout << " " << 2 << "\n";
	}
	return 0;
}