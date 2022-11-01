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
		vector <int> svi(n);
		REP(i, n) cin >> svi[i];
		REP(i, n / 2) {
			cout << svi[i] << " " << svi[n - i - 1] << " ";
		}
		if(n % 2) cout << svi[n / 2] << endl;
		else cout << endl;
	}
	return 0;
}