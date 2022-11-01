#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int offset = (1 << 19);
const int inf = 2e9;

struct tournament {
	ll suma[2 * offset];
	ll prop[2 * offset];
	void build() {
		REP(i, 2 * offset) {
			suma[i] = 0;
			prop[i] = 0;
		}
	}
	void salji_prop(int cvor, int vel) {
		suma[cvor * 2] += (ll) (vel / 2) * prop[cvor];
		suma[cvor * 2 + 1] += (ll) (vel / 2) * prop[cvor];
		prop[cvor * 2] += prop[cvor];
		prop[cvor * 2 + 1] += prop[cvor];
		prop[cvor] = 0;
		return;
	}
	void update_interval(int cvor, int a, int b, int l, int r, int kolko) {
		if(l > b || r < a) return;
		if(l >= a && r <= b) {
			suma[cvor] += (ll) (r - l + 1) * kolko;
			prop[cvor] += kolko;
			return;
		}
		salji_prop(cvor, r - l + 1);
		int mid = (l + r) / 2;
		update_interval(cvor * 2, a, b, l, mid, kolko);
		update_interval(cvor * 2 + 1, a, b, mid + 1, r, kolko);
		suma[cvor] = suma[cvor * 2] + suma[cvor * 2 + 1];
		return;
	}
	int daj_kti(int cvor, int l, int r, int k) {
		if(l == r) return l;
		salji_prop(cvor, r - l + 1);
		int mid = (l + r) / 2;
		if(suma[cvor * 2] >= k) return daj_kti(cvor * 2, l, mid, k);
		else return daj_kti(cvor * 2 + 1, mid + 1, r, k - suma[cvor * 2]);
	}
} T;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	T.build();
	T.update_interval(1, 0, 0, 0, offset - 1, 1);
	int n, k;
	cin >> n >> k;
	vector <int> svi(n);
	REP(i, n) cin >> svi[i];
	sort(svi.begin(), svi.end());
	reverse(svi.begin(), svi.end());
	ll kolko = 1;
	int rj = inf, ptr = 0;
	while(ptr < (int)svi.size()) {
		int prvi = T.daj_kti(1, 0, offset - 1, 1);
		T.update_interval(1, prvi, prvi, 0, offset - 1, -1);
		if(svi[ptr] % 2) {
			T.update_interval(1, prvi + 2, prvi + 2 + (svi[ptr] - 1) / 2 - 1, 0, offset - 1, 2);
		}
		else {
			T.update_interval(1, prvi + 2, prvi + 2 + (svi[ptr] - 2) / 2 - 1, 0, offset - 1, 2);
			T.update_interval(1, prvi + 2 + (svi[ptr] - 2) / 2, prvi + 2 + (svi[ptr] - 2) / 2, 0, offset - 1, 1);
		}
		kolko += svi[ptr] - 2;
		ptr++;
		if(kolko >= k) {
			rj = min(rj, T.daj_kti(1, 0, offset - 1, k));
		}
	}
	if(rj == inf) cout << -1 << "\n";
	else cout << rj << "\n";
	return 0;
}