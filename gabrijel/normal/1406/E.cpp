#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int pf = 0;
	vector <bool> eratosten(n + 1, 1);
	for(int i = 2; i <= n; i++) {
		if(eratosten[i]) {
			pf++;
			for(int j = i; j <= n; j += i) eratosten[j] = 0;
		}
	}
	int kor = sqrt(pf);
	bool nasao = 0;
	vector <int> svi;
	eratosten.clear();
	eratosten.insert(eratosten.begin(), n + 1, 1);
	int br = 0, uk = n, odg, prvi = -1;
	vector <int> tr;
	for(int i = 2; i <= n; i++) {
		if(eratosten[i]) {
			if(!nasao) tr.push_back(i);
			int kolko = 0;
			for(int j = i; j <= n; j += i) {
				if(eratosten[j]) {
					kolko++;
					uk--;
					eratosten[j] = 0;
				}
			}
			cout << "B " << i << "\n";
			cout << flush;
			cin >> odg;
			if(odg != kolko) svi.push_back(i);
			if(!nasao) {
				br++;
				if(br == kor) {
					br = 0;
					cout << "A " << 1 << "\n";
					cout << flush;
					cin >> odg;
					if(odg != uk) {
						nasao = 1;
						for(int f : tr) {
							cout << "A " << f << "\n";
							cout << flush;
							cin >> odg;
							if(odg) {
								prvi = f;
								break;
							}
						}
					}
					tr.clear();
				}
			}
		}
	}
	if(!nasao) {
		for(int f : tr) {
			cout << "A " << f << "\n";
			cout << flush;
			cin >> odg;
			if(odg) {
				prvi = f;
				break;
			}
		}
	}
	if(prvi != -1) svi.push_back(prvi);
	int rj = 1;
	for(int f : svi) {
		if(f > 1000) {
			rj *= f;
			continue;
		}
		int umn = f * f;
		while(1) {
			if(umn <= n) {
				cout << "A " << umn << "\n";
				cout << flush;
				cin >> odg;
			}
			if(umn > n || !odg) {
				rj *= umn / f;
				break;
			}
			umn *= f;
		}
	}
	cout << "C " << rj << "\n";
	cout << flush;
	return 0;
}