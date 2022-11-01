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
		vector <int> ele(110, 0);
		int a;
		REP(i, n) {
			cin >> a;
			ele[a]++;
		}
		int sol = 0, kol = 0;
		REP(i, 110) {
			if(ele[i] == 0) {
				sol += (2 - kol) * i;
				break;
			}
			else if(ele[i] == 1) {
				if(kol == 0) {
					kol++;
					sol += i;
				}
			}
			if(kol == 2) break;
		}
		cout << sol << "\n";
	}
	return 0;
}