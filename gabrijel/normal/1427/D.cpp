#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> svi(n);
	REP(i, n) cin >> svi[i];
	vector <vector <int> > rj;
	if(n == 1) {
		cout << "0\n";
		return 0;
	}
	REP(i, n) {
		vector <int> tr;
		bool pravo = (i % 2) ^ (n % 2);
		int pref = i;
		int poz;
		REP(j, n) {
			if(svi[j] == i + 1) {
				poz = j;
				break;
			}
		}
		int ostatak = n - pref;
		if(!pravo) REP(j, pref) tr.push_back(1);
		int poc = pravo ? 0 : pref, kraj;
		if(pravo) kraj = poz - 1;
		else kraj = poz;
		if(kraj - poc + 1 > 0) {
			tr.push_back(kraj - poc + 1);
			ostatak -= (kraj - poc + 1);
		}
		if(ostatak) tr.push_back(ostatak);
		if(pravo) REP(j, pref) tr.push_back(1);
		if(tr.size() > 1) rj.push_back(tr);
		vector <int> novi(n);
		poz = 0;
		for(int j = (int)tr.size() - 1; j >= 0; j--) {
			for(int k = 0; k < tr[j]; k++) {
				novi[poz + k] = svi[n - tr[j] - poz + k];
			}
			poz += tr[j];
		}
		svi = novi;
	}
	cout << (int)rj.size() << "\n";
	REP(i, (int)rj.size()) {
		cout << (int)rj[i].size() << " ";
		REP(j, (int)rj[i].size()) {
			cout << rj[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}