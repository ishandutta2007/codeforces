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
		int a, b, c;
		cin >> a >> b >> c;
		if((a + b + c) % 9 == 0 && min(a, min(b, c)) >= (a + b + c) / 9) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}