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
		vector <int> najv(50, 0);
		int a;
		ll sol = 0;
		REP(i, n) {
			cin >> a;
			int cnt = 0;
			while(a) {
				cnt++;
				a /= 2;
			}
			sol += najv[cnt];
			najv[cnt]++;
		}
		cout << sol << "\n";
	}
	return 0;
}