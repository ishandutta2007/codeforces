#include <bits/stdc++.h>

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

std::mt19937 mt(48);

namespace kactl {
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1000000007; // faster if const

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

int matInv(vector<vector<ll>>& A) {
	int n = sz(A); vi col(n);
	vector<vector<ll>> tmp(n, vector<ll>(n));
	rep(i,0,n) tmp[i][i] = 1, col[i] = i;

	rep(i,0,n) {
		int r = i, c = i;
		rep(j,i,n) rep(k,i,n) if (A[j][k]) {
			r = j; c = k; goto found;
		}
		return i;
found:
		A[i].swap(A[r]); tmp[i].swap(tmp[r]);
		rep(j,0,n) swap(A[j][i], A[j][c]), swap(tmp[j][i], tmp[j][c]);
		swap(col[i], col[c]);
		ll v = modpow(A[i][i], mod - 2);
		rep(j,i+1,n) {
			ll f = A[j][i] * v % mod;
			A[j][i] = 0;
			rep(k,i+1,n) A[j][k] = (A[j][k] - f*A[i][k]) % mod;
			rep(k,0,n) tmp[j][k] = (tmp[j][k] - f*tmp[i][k]) % mod;
		}
		rep(j,i+1,n) A[i][j] = A[i][j] * v % mod;
		rep(j,0,n) tmp[i][j] = tmp[i][j] * v % mod;
		A[i][i] = 1;
	}

	for (int i = n-1; i > 0; --i) rep(j,0,i) {
		ll v = A[j][i];
		rep(k,0,n) tmp[j][k] = (tmp[j][k] - v*tmp[i][k]) % mod;
	}

	rep(i,0,n) rep(j,0,n)
		A[col[i]][col[j]] = tmp[i][j] % mod + (tmp[i][j] < 0 ? mod : 0);
	return n;
}

vector<pii> generalMatching(int N, const vector<pii>& ed) {
	vector<vector<ll>> mat(N, vector<ll>(N)), A;
	for (pii pa : ed) {
		int a = pa.first, b = pa.second, r = mt() % mod;
		mat[a][b] = r, mat[b][a] = (mod - r) % mod;
	}

	int r = matInv(A = mat), M = 2*N - r, fi, fj;
	assert(r % 2 == 0);

	if (M != N) do {
		mat.resize(M, vector<ll>(M));
		rep(i,0,N) {
			mat[i].resize(M);
			rep(j,N,M) {
				int r = mt() % mod;
				mat[i][j] = r, mat[j][i] = (mod - r) % mod;
			}
		}
	} while (matInv(A = mat) != M);

	vi has(M, 1); vector<pii> ret;
	rep(it,0,M/2) {
		rep(i,0,M) if (has[i])
			rep(j,i+1,M) if (A[i][j] && mat[i][j]) {
				fi = i; fj = j; goto done;
		} assert(0); done:
		if (fj < N) ret.emplace_back(fi, fj);
		has[fi] = has[fj] = 0;
		rep(sw,0,2) {
			ll a = modpow(A[fi][fj], mod-2);
			rep(i,0,M) if (has[i] && A[i][fj]) {
				ll b = A[i][fj] * a % mod;
				rep(j,0,M) A[i][j] = (A[i][j] - A[fi][j] * b) % mod;
			}
			swap(fi,fj);
		}
	}
	return ret;
}
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	std::vector<int> A(N);
	for (auto& a : A) { cin >> a; a--; }

	std::vector<int> par(N+1, -1);
	auto get_par = [&](int a) -> int {
		while (par[a] >= 0) {
			if (par[par[a]] >= 0) par[a] = par[par[a]];
			a = par[a];
		}
		return a;
	};
	auto merge = [&](int a, int b) -> bool {
		a = get_par(a);
		b = get_par(b);
		if (a == b) return false;
		if (par[a] > par[b]) std::swap(a, b);
		par[a] += par[b];
		par[b] = a;
		return true;
	};

	std::vector<std::pair<int, int>> nonzero; nonzero.reserve(N+2);
	nonzero.push_back({-1, N});
	for (int i = 0; i < N; i++) {
		if (A[i] != -1) {
			nonzero.push_back({i, A[i]});
		}
	}
	nonzero.push_back({N, N});

	std::vector<std::vector<std::pair<int, int>>> adj(N+1);
	std::vector<bool> done(N+1);
	done[N] = true;

	auto dfs = std::y_combinator([&](auto self, int cur) -> void {
		assert(done[cur]);
		for (auto [nxt, nv] : adj[cur]) {
			if (done[nxt]) continue;
			done[nxt] = true;
			assert(A[nv] == -1);
			A[nv] = nxt;
			self(nxt);
		}
	});

	for (int z = 0; z+1 < int(nonzero.size()); z++) {
		auto [lp, lv] = nonzero[z];
		auto [rp, rv] = nonzero[z+1];

		int zero = rp - lp - 1;
		if (zero & 1) {
		} else if (zero == 0) {
			if (lv == rv) {
				done[lv] = true;
			}
		} else {
			// continue for now
		}
	}

	for (int z = 0; z+1 < int(nonzero.size()); z++) {
		auto [lp, lv] = nonzero[z];
		auto [rp, rv] = nonzero[z+1];

		int zero = rp - lp - 1;
		if (zero & 1) {
			if (done[lv] && done[rv]) {
				// we're just good
			} else if (done[lv]) {
				done[rv] = true;
				A[rp-1] = rv;
				dfs(rv);
			} else if (done[rv]) {
				done[lv] = true;
				A[lp+1] = lv;
				dfs(lv);
			} else if (get_par(lv) == get_par(rv)) {
				done[lv] = true;
				A[lp+1] = lv;
				dfs(lv);
				assert(done[rv]);
			} else {
				adj[lv].push_back({rv, rp-1});
				adj[rv].push_back({lv, lp+1});
				merge(lv, rv);
			}
		} else if (zero == 0) {
		} else {
			// continue for now
		}
	}

	std::vector<std::pair<std::pair<int, int>, int>> edges; edges.reserve(nonzero.size());

	std::vector<int> non_done_id(N, -1);
	int V = 0;

	for (int z = 0; z+1 < int(nonzero.size()); z++) {
		auto [lp, lv] = nonzero[z];
		auto [rp, rv] = nonzero[z+1];

		int zero = rp - lp - 1;
		if (zero & 1) {
		} else if (zero == 0) {
		} else {
			if (done[lv] || done[rv]) continue;
			lv = get_par(lv);
			rv = get_par(rv);
			if (lv == rv) continue;

			if (non_done_id[lv] == -1) non_done_id[lv] = V++;
			lv = non_done_id[lv];

			if (non_done_id[rv] == -1) non_done_id[rv] = V++;
			rv = non_done_id[rv];

			edges.push_back({{std::min(lv, rv), std::max(lv, rv)}, z});
		}
	}

	//V = std::max(V, 600);

	std::sort(edges.begin(), edges.end());
	edges.resize(std::unique(edges.begin(), edges.end(), [&](auto a, auto b) { return a.first == b.first; }) - edges.begin());

	std::vector<std::pair<int, int>> kactl_edges(edges.size());
	for (int i = 0; i < int(edges.size()); i++) kactl_edges[i] = edges[i].first;
	auto matching_edges = kactl::generalMatching(V, kactl_edges);
	for (auto ed : matching_edges) {
		if (ed.first > ed.second) std::swap(ed.first, ed.second);

		int z = std::lower_bound(edges.begin(), edges.end(), std::make_pair(ed, -1))->second;

		auto [lp, lv] = nonzero[z];
		auto [rp, rv] = nonzero[z+1];
		assert(A[lp+1] == -1);
		A[lp+1] = lv;
		assert(A[rp-1] == -1);
		A[rp-1] = rv;

		assert(!done[lv]);
		assert(!done[rv]);
		done[lv] = done[rv] = true;

		dfs(lv);
		dfs(rv);
	}

	// Fill out remaining trees
	for (int i = N; i >= 0; i--) {
		if (!done[i]) {
			done[i] = true;
			dfs(i);
			done[i] = false;
		}
	}

	int v = 0;
	for (int i = 0; i < N; i++) {
		if (i+1 < N && A[i] == -1 && A[i+1] == -1) {
			while (v < N && done[v]) v++;
			A[i] = A[i+1] = v;
			if (v <= N) {
				done[v] = true;
			}
		} else if (A[i] == -1) {
			A[i] = 0;
		}

		cout << std::min(A[i]+1, N) << " \n"[i+1==N];
	}

	return 0;
}