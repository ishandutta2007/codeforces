#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int mod = 1e9 + 7;

inline int add(int a, int b) {a += b; if(a >= mod) a-= mod; if(a < 0) a += mod; return a;}
inline int mult(int a, int b) {return (long long) a * b % mod;}
inline int pot(int a, int b) {int ret = 1; while(b){if(b & 1) ret = mult(ret, a); a = mult(a, a); b >>= 1;} return ret;}
inline int divide(int a, int b) {return mult(a, pot(b, mod - 2));}

int fakt(int x) {
	int ret = 1;
	for(int i = 1; i <= x; i++) {
		ret = mult(ret, i);
	}
	return ret;
}

int povrh(int a, int b) {
	return divide(fakt(a), mult(fakt(b), fakt(a - b)));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, pos;
	cin >> n >> x >> pos;
	int lo = 0, hi = n, mid, veci = 0, manji = 0;
	while(lo < hi) {
		mid = (lo + hi) / 2;
		if(mid == pos) {
			lo = mid + 1;
		}
		else if(mid < pos) {
			manji++;
			lo = mid + 1;
		}
		else {
			veci++;
			hi = mid;
		}
	}
	if(veci > n - x || manji > x - 1) {
		cout << "0\n";
		return 0;
	}
	int rj = 1;
	if(veci) rj = mult(rj, povrh(n - x, veci));
	if(manji) rj = mult(rj, povrh(x - 1, manji));
	rj = mult(rj, fakt(n - 1 - veci - manji));
	rj = mult(rj, fakt(veci));
	rj = mult(rj, fakt(manji));
	cout << rj << "\n";
	return 0;
}