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
		int zad = 1e9 + 7;
		bool da = 0;
		REP(i, n) {
			if(svi[i] >= zad) {
				da = 1;
				break;
			}
			zad = svi[i];
		}
		if(da) {
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
	return 0;
}