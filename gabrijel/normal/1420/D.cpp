#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int mod = 998244353;

inline int add(int a, int b) {a += b; if(a >= mod) a-= mod; if(a < 0) a += mod; return a;}
inline int mult(int a, int b) {return (long long) a * b % mod;}
inline int pot(int a, int b) {int ret = 1; while(b){if(b & 1) ret = mult(ret, a); a = mult(a, a); b >>= 1;} return ret;}
inline int divide(int a, int b) {return mult(a, pot(b, mod - 2));}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector <int> fakt(n + 2), inv(n + 2);
	fakt[0] = 1;
	inv[0] = 1;
	for(int i = 1; i <= n; i++) {
		fakt[i] = mult(fakt[i - 1], i);
		inv[i] = pot(fakt[i], mod - 2);
	}
	vector <pair <int, int> > eve;
	int a, b;
	REP(i, n) {
		cin >> a >> b;
		eve.push_back(make_pair(a, -1));
		eve.push_back(make_pair(b, 1));
	}
	sort(eve.begin(), eve.end());
	int akt = 0;
	ll rj = 0;
	REP(i, (int)eve.size()) {
		if(eve[i].second == 1) akt--;
		else {
			akt++;
			if(akt >= k) {
				rj = add(rj, mult(fakt[akt - 1], mult(inv[k - 1], inv[akt - k])));
			}
		}
	}
	cout << rj << "\n";
	return 0;
}