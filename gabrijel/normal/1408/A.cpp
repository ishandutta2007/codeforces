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
		vector <int> svi[3];
		int a;
		REP(i, 3) {
			REP(j, n) {
				cin >> a;
				svi[i].push_back(a);
			}
		}
		int zad = -1, poc;
		REP(i, n) {
			if(i == 0) {
				poc = svi[0][i];
				zad = poc;
			}
			else if(i == n - 1) {
				if(svi[0][i] != zad && svi[0][i] != poc) zad = svi[0][i];
				else if(svi[1][i] != zad && svi[1][i] != poc) zad = svi[1][i];
				else zad = svi[2][i];
			}
			else {
				REP(j, 3) {
					if(svi[j][i] != zad) {
						zad = svi[j][i];
						break;
					}
				}
			}
			cout << zad << " ";
		}
		cout << "\n";
	}
	return 0;
}