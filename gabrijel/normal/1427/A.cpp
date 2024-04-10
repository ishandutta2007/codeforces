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
		sort(svi.begin(), svi.end());
		int suma = 0, suma2 = 0;
		vector <int> rj, rj2;
		REP(i, n) {
			if(svi[i] >= 0) break;
			suma -= svi[i];
			rj.push_back(svi[i]);
		}
		for(int i = n - 1; i >= 0; i--) {
			if(svi[i] < 0) break;
			suma2 += svi[i];
			rj2.push_back(svi[i]);
		}
		if(suma2 == suma) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			if(suma2 > suma) {
				for(int i = 0; i < (int)rj2.size(); i++) cout << rj2[i] << " ";
				for(int i = (int)rj.size() - 1; i >= 0; i--) cout << rj[i] << " ";
			}
			else {
				for(int i = (int)rj.size() - 1; i >= 0; i--) cout << rj[i] << " ";
				for(int i = 0; i < (int)rj2.size(); i++) cout << rj2[i] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}