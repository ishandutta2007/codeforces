#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef LOCAL
#define debug(...) {\
    std::cout << "[" << __FUNCTION__ << ":" << __LINE__ << "] " << #__VA_ARGS__ << " "  << __VA_ARGS__ << std::endl;\
    }
#else
#define debug(...)
#endif

const long long mod = 1000000007;
#define MOD(x) ((x)%mod)
long long power(long long x, long long n) {
	int i = 0;
	long long d = x;
	long long ats = 1;

	while (n > 0) {
		if (n & (1ll << i)) {
			n ^= (1ll << i);
			ats *= d;
			ats %= mod;
		}

		i++;
		d = (d * d) % mod;
	}

	return ats;
}
/*input
3 3
aa
bcd
2 aba
3 ca
3 aa
*/
/*input
4 5
aba
bbac
1 a
3 baca
3 ab
2 bab
4 aba
*/
/*input
4 5
aaa
aaaa
4 aaa
4 aaaa
4 aaaaa
4 aaaaaa
4 aaaaaaa
*/
/*input
3 6
aaa
aaa
2 aaa
2 aaaa
2 aaaaa
2 aaaaaaaa
2 aaaaaaaaaaaaaaa
2 aaaaaaaaaaaaaaaa
*/
long long kart[100000 + 1][30] = {};
long long n, q;
string s, t;
int k;

long long rez(string eil, int tt) {
	if (eil.size() == 1) {
		long long del = MOD(kart[k][eil[0] - 'a'] - MOD(kart[tt][eil[0] - 'a'] * power(2, k - tt)));
		return del;
	}

	if (eil.size() == 0 or tt >= (int)k) {
        return 0;
	}

	bool tink0 = true;
	bool tink1 = true;

	for (int i = 0; i < (int)eil.size(); i += 2) {
		if (eil[i] != t[tt]) {
			tink0 = false;
			break;
		}
	}

	for (int i = 1; i < (int)eil.size(); i += 2) {
		if (eil[i] != t[tt]) {
			tink1 = false;
			break;
		}
	}

	long long ans = 0;

	if (tink0) {
		string eil2;

		for (int i = 1; i < (int)eil.size(); i += 2) {
			eil2.push_back(eil[i]);
		}

		ans += rez(eil2, tt + 1);
	}

	if (tink1) {
		string eil2;

		for (int i = 0; i < (int)eil.size(); i += 2) {
			eil2.push_back(eil[i]);
		}

		ans += rez(eil2, tt + 1);
	}

	return MOD(ans);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	cin >> s >> t;

	for (int i = 0; i < n; ++i) {
		for (char c = 'a'; c <= 'z'; ++c) {
			kart[i + 1][c - 'a'] = MOD(kart[i][c - 'a'] * 2);
		}

		kart[i + 1][t[i] - 'a']++;
	}

	for (int i = 0; i < q; ++i) {
		cin >> k;
		string w;
		cin >> w;

		if (w.size() <= s.size()) {
			long long kie = 0;

			for (int pr = 0; pr <= (int)s.size(); ++pr) {
				int d = pr;
				bool blog = false;
				char simb = 0;

				for (int j = 0; j < (int)w.size(); ++j) {
					if (d == (int)s.size()) {
						simb = w[j];
						d = 0;
					}
					else {
						if (w[j] != s[d]) {
							blog = true;
							break;
						}

						d++;
					}
				}

				if (blog) {
					continue;
				}

				if (simb) {
					kie += kart[k][simb - 'a'];
				}
				else {
					kie += power(2, k);
				}

				kie = MOD(kie);
			}

			cout << kie << "\n";
		}
		else {
			long long kie = 0;

			for (int pr = 0; pr <= (int)s.size(); ++pr) {
				int d = pr;
				bool blog = false;
				string eil;

				for (int j = 0; j < (int)w.size(); ++j) {
					if (d == (int)s.size()) {
						eil.push_back(w[j]);
						d = 0;
					}
					else {
						if (w[j] != s[d]) {
							blog = true;
							break;
						}

						d++;
					}
				}

				if (blog) {
					continue;
				}

				kie = MOD(kie + rez(eil, 0));
			}

			kie = MOD(kie);

			if (kie < 0) {
				kie += mod;
			}

			kie = MOD(kie);

			cout << kie << "\n";
		}

	}
}