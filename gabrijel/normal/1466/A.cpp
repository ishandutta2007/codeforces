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
		map <int, bool> imam;
		int rj = 0;
		REP(i, n) {
			cin >> svi[i];
			REP(j, i) {
				if(!imam[svi[i] - svi[j]]) {
					rj++;
					imam[svi[i] - svi[j]] = 1;
				}
			}
		}
		cout << rj << endl;
	}
	return 0;
}