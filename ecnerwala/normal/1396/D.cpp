#include<bits/stdc++.h>
#include <numeric>

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
	friend modnum inv(const modnum& m) { return m.inv(); }
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum& m) { return m.neg(); }

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

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, K; int L; cin >> N >> K >> L;

	using num = modnum<int(1e9)+7>;
	struct candy {
		array<int, 2> p;
		int c;
	};
	vector<candy> C(N);
	for (int i = 0; i < N; i++) {
		int x, y, c; cin >> x >> y >> c; c--;
		C[i].p = {x,y};
		C[i].c = c;
	}

	array<vector<num>, 2> weights;
	for (int z = 0; z < 2; z++) {
		sort(C.begin(), C.end(), [&](const candy& a, const candy& b) { return a.p[z] < b.p[z]; });
		// now they're weights
		weights[z].resize(N+2);
		weights[z][0] = num(-1);
		for (int i = 0; i < N; i++) {
			weights[z][i+1] = num(C[i].p[z]);
		}
		weights[z][N+1] = num(L);

		for (int i = 0; i < N; i++) {
			C[i].p[z] = i;
		}
	}

	weights[0].push_back(num(L)); // push it back again

	// increasing y
	sort(C.begin(), C.end(), [&](const candy& a, const candy& b) { return a.p[1] < b.p[1]; });

	for (int i = 0; i < N; i++) {
		assert(C[i].p[1] == i);
		//cerr << i << ' ' << C[i].c << ' ' << C[i].p[0] << ',' << C[i].p[1] << '\n';
	}

	num ans = 0;
	for (int xlo = 0; xlo < N; xlo++) {
		//cerr << "xlo = " << xlo << '\n';

		vector<vector<array<int, 2>>> evts(N+1);

		vector<vector<array<int, 2>>> pts(K, vector<array<int, 2>>({{xlo-1, -1}, {N, -1}}));

		for (int y = 0; y < N; y++) {
			if (C[y].p[0] < xlo) continue;

			int k = C[y].c;
			evts[y].push_back({N, pts[k].back()[1]+1});
			while (!pts[k].empty() && pts[k].back()[0] > C[y].p[0]) {
				auto p = pts[k].back();
				pts[k].pop_back();
				// xhi, ylo
				evts[y].push_back({p[0], pts[k].back()[1]+1});
				//cerr << "evt " << k << ' ' << y << ' ' << p[0] << ' ' << pts[k].back()[1]+1 << '\n';
			}
			pts[k].push_back(C[y].p);
		}

		for (int k = 0; k < K; k++) {
			evts[N].push_back({N, pts[k].back()[1]+1});
			while (pts[k].size() >= 2) {
				auto p = pts[k].back();
				pts[k].pop_back();
				// xhi, ylo
				evts[N].push_back({p[0], pts[k].back()[1]+1});
				//cerr << "evt " << k << ' ' << N << ' ' << p[0] << ' ' << pts[k].back()[1]+1 << '\n';
			}
		}

		set<array<int, 2>> bads;
		bads.insert({xlo, -1});
		bads.insert({N, N+1});
		auto eval = [&](array<int, 2> l, array<int, 2> r) -> num {
			assert(l[0] >= xlo && r[1] >= l[1]);
			if (l[0] == xlo) return 0;
			return (weights[0][l[0]+1] - weights[0][xlo+1]) * (weights[1][r[1]] - weights[1][l[1]]);
		};

		num curVal = eval(*bads.begin(), *bads.rbegin());
		for (int yhi = N; yhi > 0; yhi--) {
			evts[yhi].push_back({N, yhi});
			for (auto p : evts[yhi]) {
				//cerr << p[0] << ' ' << p[1] << '\n';
				auto nt = bads.lower_bound(p);
				if ((*nt)[1] <= p[1]) continue;
				auto pt = nt; --pt;
				curVal -= eval(*pt, *nt);
				while ((*pt)[1] > p[1]) {
					auto ppt = pt; --ppt;
					curVal -= eval(*ppt, *pt);
					bads.erase(pt);
					pt = ppt;
				}
				curVal += eval(*pt, p);
				curVal += eval(p, *nt);
				bads.insert(nt, p);
			}
			num v = (weights[0][xlo+1] - weights[0][xlo]) * (weights[1][yhi+1] - weights[1][yhi]) *
				(curVal - eval({N, yhi}, {N, N+1}));
			//for (auto it : bads) { cerr << it[0] << ' ' << it[1] << '\n'; }
			//cerr << xlo << ' ' << yhi << ' ' << curVal << ' ' << curVal - eval({N, yhi}, {N, N+1}) << ' ' << v << '\n';
			ans += v;
		}
	}

	array<num, 2> tot{0,0};
	for (int z = 0; z < 2; z++) {
		for (int i = 0; i <= N; i++) {
			for (int j = i+1; j <= N; j++) {
				tot[z] += (weights[z][i+1] - weights[z][i]) * (weights[z][j+1] - weights[z][j]);
			}
		}
	}
	//cerr << tot[0] << ' ' << tot[1] << ' ' << ans << '\n';
	ans = tot[0] * tot[1] - ans;

	cout << ans << '\n';

	return 0;
}