#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const ll inf = 1e18;

int n, q, a, b;

vector <ll> pridonos;

ll sol = 0;

vector <int> svi;

void izracunaj_pridonos(int ind) {
	if(ind == 0) {
		if(svi[ind + 1] < svi[ind]) {
			sol -= pridonos[ind];
			pridonos[ind] = svi[ind];
			sol += pridonos[ind];
		}
		else {
			sol -= pridonos[ind];
			pridonos[ind] = 0;
		}
	}
	else if(ind == n - 1) {
		if(svi[ind - 1] < svi[ind]) {
			sol -= pridonos[ind];
			pridonos[ind] = svi[ind];
			sol += pridonos[ind];
		}
		else {
			sol -= pridonos[ind];
			pridonos[ind] = 0;
		}
	}
	else {
		if(svi[ind - 1] > svi[ind] && svi[ind + 1] < svi[ind]) {
			sol -= pridonos[ind];
			pridonos[ind] = 0;
		}
		else if(svi[ind - 1] > svi[ind]) {
			sol -= pridonos[ind];
			pridonos[ind] = -svi[ind];
			sol += pridonos[ind];
		}
		else if(svi[ind + 1] < svi[ind]) {
			sol -= pridonos[ind];
			pridonos[ind] = svi[ind];
			sol += pridonos[ind];
		}
		else {
			sol -= pridonos[ind];
			pridonos[ind] = 0;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		cin >> n >> q;
		sol = 0;
		pridonos.clear();
		svi.clear();
		svi.resize(n);
		pridonos.resize(n, 0LL);
		REP(i, n) cin >> svi[i];
		if(n == 1) {
			cout << svi[0] << "\n";
			REP(i, q) {
				cin >> a >> b;
				cout << svi[0] << "\n";
			}
			continue;
		}
		REP(i, n) {
			izracunaj_pridonos(i);
		}
		cout << sol << "\n";
		REP(qq, q) {
			cin >> a >> b;
			a--; b--;
			if(a == b) {
				cout << sol << "\n";
				continue;
			}
			swap(svi[a], svi[b]);
			for(int i = a - 2; i <= a + 2; i++) {
				if(i >= 0 && i < n) izracunaj_pridonos(i);
			}
			for(int i = b - 2; i <= b + 2; i++) {
				if(i >= 0 && i < n) izracunaj_pridonos(i);
			}
			cout << sol << "\n";
		}
	}
	return 0;
}