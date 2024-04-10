#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int maxn = 1e5;

vector <int> prosti;
int djelitelj[maxn + 100];

void euler() {
	for(int i = 2; i <= maxn; i++) {
		if(!djelitelj[i]) prosti.push_back(i);
		for(int j = 0; i * prosti[j] < maxn; j++) {
			djelitelj[i * prosti[j]] = prosti[j];
			if(i % prosti[j] == 0) break;
		}
	}
	return;
}

int n, pn;

vector <int> pf;
unordered_map <int, bool> mapa;
vector <int> rj;

vector <int> tr_d;

void rek(int tr) {
	tr_d.push_back(tr);
	mapa[tr] = 1;
	REP(i, (int)pf.size()) {
		if((ll) tr * pf[i] > n) continue;
		if(mapa[tr * pf[i]]) continue;
		if(n % (tr * pf[i]) == 0) rek(tr * pf[i]);
	}
	return;
}

int gcd(int a, int b) {
	if(!b) return a;
	return gcd(b, a % b);
}

int main() {
	euler();
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		cin >> n;
		pn = n;
		pf.clear();
		rj.clear();
		REP(i, (int)prosti.size()) {
			if(pn % prosti[i] == 0) pf.push_back(prosti[i]);
			while(pn % prosti[i] == 0) pn /= prosti[i];
		}
		if(pn > 1) {
			pf.push_back(pn);
		}
		if((int)pf.size() == 1) {
			ll tr = pf[0];
			while(tr <= n) {
				cout << tr << " ";
				tr *= pf[0];
			}
			cout << "\n0\n";
			continue;
		}
		for(int i = (int)pf.size() - 1; i >= 0; i--) {
			tr_d.clear();
			vector <int> novi;
			rek(pf[i]);
			int prvi = -1, drugi = -1;
			REP(j, (int)tr_d.size()) {
				if(i == (int)pf.size() - 1 && tr_d[j] % pf[0] == 0) {
					if(prvi == -1) {
						prvi = tr_d[j];
					}
					else {
						novi.push_back(tr_d[j]);
					}
				}
				else if(i > 0 && tr_d[j] % pf[i - 1] == 0) {
					if(drugi == -1) {
						drugi = tr_d[j];
					}
					else {
						novi.push_back(tr_d[j]);
					}
				}
				else novi.push_back(tr_d[j]);
			}
			if(prvi != -1) rj.push_back(prvi);
			REP(j, (int)novi.size()) rj.push_back(novi[j]);
			if(drugi != -1) rj.push_back(drugi);
		}
		int zad = -1, rj2 = 0;
		REP(i, (int)rj.size()) {
			cout << rj[i] << " ";
			mapa[rj[i]] = 0;
			if(zad != -1) {
				 if(gcd(zad, rj[i]) == 1) rj2++;
			}
			zad = rj[i];
		}
		if(gcd(zad, rj[0]) == 1) rj2++;
		cout << "\n";
		cout << rj2 << "\n";
	}
	return 0;
}