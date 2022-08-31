#include<bits/stdc++.h>
using namespace std;

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");

private:
	using ll = long long;

	int v;

	static int minv(int a, int m) {
		a %= m;
		assert(a);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}

public:

	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}

	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}

	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
using num = modnum<998244353>;
num powmod(num a, int b) {
	num r = 1;
	while (b) {
		if (b & 1) {
			r *= a;
		}
		a *= a;
		b /= 2;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string S; cin >> S;
	int M = int(S.size());
	reverse(S.begin(), S.end());
	num res = 0;
	for (int L = 1; L < M; L++) {
		int V = 2 * M;
		V = 2 * M;
		vector<vector<pair<int, int>>> adj(V);

		for (int i = 0; i < L-1-i; i++) {
			adj[M+i].emplace_back(M+L-1-i, 0);
			adj[M+L-1-i].emplace_back(M+i, 0);
		}
		for (int i = 0; i < M-1-i; i++) {
			adj[i].emplace_back(M-1-i, 0);
			adj[M-1-i].emplace_back(i, 0);
		}

		for (int i = 0; i < M; i++) {
			if (S[i] != '?') {
				assert(S[i] == '0' || S[i] == '1');
				adj[i].emplace_back(M + i, S[i] - '0');
				adj[M + i].emplace_back(i, S[i] - '0');
			}
		}

		for (int i = L; i < M; i++) {
			adj[M+i].emplace_back(-1, 0);
		}

		for (int i = 0; i < V; i++) assert(adj[i].size() <= 2);

		bool foundM = false;

		if (adj[M].size() <= 1) {
			adj[M].emplace_back(-1, 1);
			foundM = true;
		}

		assert(foundM || adj[M].size() == 2);

		int rnk = V;
		for (int st = 0; st < V; st++) {
			int cur = st;
			while (cur != -1 && adj[cur].size() == 1) {
				if (!foundM && cur == M) {
					// add the extra edge
					adj[cur].emplace_back(-1, 1);
					foundM = true;
					break;
				}
				rnk--;
				// remove the chain
				int nxt = adj[cur][0].first;
				adj[cur].clear();
				if (nxt != -1) {
					int z = 0; while (adj[nxt][z].first != cur) z++;
					adj[nxt].erase(adj[nxt].begin() + z);
				}
				cur = nxt;
			}
		}

		assert(foundM || adj[M].size() == 2);

		for (int st = 0; st < V; st++) {
			assert(adj[st].size() == 2 || adj[st].size() == 0);
		}
		for (int st = V-1; st >= 0; st--) {
			if (adj[st].empty()) continue;
			assert(adj[st].size() == 2);
			int sum = 0;
			int cur = st;
			int prv = adj[st].back().first;
			bool hasM = true;
			do {
				if (!foundM && cur == M) {
					if (st >= L+M) {
						if (sum != 1) {
							goto UNSAT;
						} else {
							// no action
						}
					} else {
						hasM = true;
					}
					foundM = true;
				}
				int z = 0; while (adj[cur][z].first == prv) z++;
				int nxt = adj[cur][z].first;
				sum ^= adj[cur][z].second;
				adj[cur].clear();
				prv = cur; cur = nxt;
				rnk--;
			} while (cur != st && cur != -1);

			if (sum != 0) {
				goto UNSAT;
			}

			if (cur == -1 || hasM) {
				// rank got subtracted by length of cycle
			} else {
				rnk++;
			}
		}
		//cerr << L <<  ' ' << L + M << ' ' << L + M - L/2 - M/2 - 1 - 1 << ' ' << rnk << '\n';
		if (rnk < 0) {
			continue;
		}
		//cerr << powmod(2, rnk) << '\n';
		res += powmod(2, rnk);
UNSAT:;
	}
	cout << res << '\n';

	return 0;
}