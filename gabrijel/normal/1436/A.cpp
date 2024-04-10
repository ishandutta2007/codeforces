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
		int n, m;
		cin >> n >> m;
		int a, suma = 0;
		REP(i, n) {
			cin >> a;
			suma += a;
		}
		if(suma == m) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}