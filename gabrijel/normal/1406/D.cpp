#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int maxn = 100100;

ll fen[maxn];

void update(int ind, int x) {
	ind++;
	for(int i = ind; i < maxn; i += i&-i) fen[i] += x;
	return;
}

ll daj(int ind) {
	ind++;
	ll ret = 0;
	for(int i = ind; i > 0; i -= i&-i) ret += fen[i];
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n;
	int zad, a, b, c;
	ll p, d = 0, nes;
	cin >> p;
	update(0, p);
	update(1, -p);
	zad = p;
	REP(i, n - 1) {
		cin >> a;
		update(i + 1, a);
		update(i + 2, -a);
		if(a - zad > 0) {
			d += a - zad;
		}
		zad = a;
	}
	cin >> q;
	if(p - d < 0) cout << (p - d) / 2 + d << "\n";
	else cout << (p - d + 1) / 2 + d << "\n";
	REP(qq, q) {
		cin >> a >> b >> c;
		a--; b--;
		if(a == 0) {
			p += c;
		}
		else {
			nes = daj(a) - daj(a - 1);
			if(nes > 0) d -= nes;
			nes += c;
			if(nes > 0) d += nes;
		}
		if(b != n - 1) {
			nes = daj(b + 1) - daj(b);
			if(nes > 0) d -= nes;
			nes -= c;
			if(nes > 0) d += nes;
		}
		update(a, c);
		update(b + 1, -c);
		if(p - d < 0) cout << (p - d) / 2 + d << "\n";
		else cout << (p - d + 1) / 2 + d << "\n";
	}
	return 0;
}