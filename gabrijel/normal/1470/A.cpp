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
		vector <int> svi(n);
		REP(i, n) cin >> svi[i];
		sort(svi.begin(), svi.end());
		reverse(svi.begin(), svi.end());
		vector <int> pokloni(m);
		REP(i, m) cin >> pokloni[i];
		int ptr = 0;
		ll rj = 0;
		for(int pr : svi) {
			if(pr <= ptr + 1) rj += pokloni[pr - 1];
			else rj += pokloni[ptr];
			ptr++;
		}
		cout << rj << "\n";
	}
	return 0;
}