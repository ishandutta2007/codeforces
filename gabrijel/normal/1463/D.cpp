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
		int n, a;
		cin >> n;
		vector <bool> svi(2 * n, 0);
		REP(i, n) {
			cin >> a;
			svi[a - 1] = 1;
		}
		int mini = 0, maxi = 0, viska = 0;
		REP(i, 2 * n) {
			if(svi[i]) {
				if(viska) viska--;
				else mini++;
			}
			else viska++;
		}
		reverse(svi.begin(), svi.end());
		viska = 0;
		REP(i, 2 * n) {
			if(svi[i]) {
				if(viska) {
					maxi++;
					viska--;
				}
			}
			else viska++;
		}
		//cout << mini << " " << maxi << endl;
		cout << maxi - mini + 1 << endl;
	}
	return 0;
}