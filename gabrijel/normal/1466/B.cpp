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
		int rj = 0;
		REP(i, n) {
			if(i == 0) rj++;
			else {
				if(svi[i] < svi[i - 1]) {
					svi[i]++;
				}
				else if(svi[i] == svi[i - 1]) {
					rj++;
					svi[i]++;
				}
				else rj++;
			}
		}
		cout << rj << "\n";
	}
	return 0;
}