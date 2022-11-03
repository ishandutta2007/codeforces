#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
const db PI = acos(-1);

random_device rd;
mt19937 rnd32(rd());
mt19937_64 rnd64(rd());

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
T square(T a) {
	return a * a;
}

template<>
struct std::hash<pair<ll, ll>> {
	ll operator() (pair<ll, ll> p) {
		return ((__int128)p.first * MOD + p.second) % INF64;
	}
};

void solve() {
	ll a1, b1, c1, a2, b2, c2;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	ll all, nc, nb, ta, na, tb, tc;
	cin >> all >> nc >> nb >> ta >> na >> tb >> tc;
	ll pall = 0, pnc = 0, pnb = 0, pna = 0;
	bool b = false;
	for (ll i = 0; i <= nc; i++) {
		a1 -= i;
		b1 -= i;
		a2 -= nc - i;
		b2 -= nc - i;
		for (ll j = 0; j <= nb; j++) {
			a1 -= j;
			c1 -= j;
			a2 -= nb - j;
			c2 -= nb - j;
			ll mbc = min(b1, c1);
			ll mabc = min(min(mbc, a1), all);
			all -= mabc;
			mbc -= mabc;
			assign_min(mbc, na);
			na -= mbc;
			if (a2 >= all && b2 >= all + na && c2 >= all + na) {
				a1 -= mabc;
				b1 -= mabc;
				c1 -= mabc;
				b1 -= mbc;
				c1 -= mbc;
				a2 -= all;
				b2 -= all;
				c2 -= all;
				b2 -= na;
				c2 -= na;
				pall = mabc;
				pna = mbc;
				pnc = i;
				pnb = j;
				b = true;
				break;
			}
			all += mabc;
			na += mbc;
			a1 += j;
			c1 += j;
			a2 += nb - j;
			c2 += nb - j;
		}
		if (b) {
			break;
		}
		a1 += i;
		b1 += i;
		a2 += nc - i;
		b2 += nc - i;
	}
	if (!b) {
		cout << -1 << '\n';
		return;
	}
	ll pa = min(a1, ta), pb = min(b1, tb), pc = min(c1, tc);
	ta -= pa;
	tb -= pb;
	tc -= pc;
	if (a2 < ta || b2 < tb || c2 < tc) {
		cout << -1 << '\n';
		return;
	}
	cout << pall << ' ' << pnc << ' ' << pnb << ' ' << pa << ' ' << pna << ' ' << pb << ' ' << pc << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}