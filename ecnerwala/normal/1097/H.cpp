#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXD = 25;
const int MAXM = 61;
int D, M;
int gen[MAXD];


map<ll, vector<ll>> mem;
vector<ll>& dfs2(ll H) {
	assert(H >= 0);
	if (mem.count(H)) {
		return mem[H];
	}
	auto& res = mem[H] = vector<ll>(size_t(M));
	if (H == 0) {
		res[0]++;
		return res;
	}
	for (int d = 0; d < D && d <= H; d++) {
		vector<ll>& o = dfs2((H-d) / D);
		for (int i = 0; i < M; i++) {
			res[(i+gen[d]) % M] += o[i];
		}
	}
	return res;
}

map<ll, vector<ll>> results;
// maximum starting point (inclusive)
void dfs(const vector<uint64_t> &B, ll H) {
	if (H < 0) {
		return;
	}

	assert(H >= 0);

	const int N = int(B.size());

	if (N == 1) {
		if (!results.count(H)) {
			results[H] = vector<ll>(M);
		}
		vector<ll>& v = results[H];
		for (int m = 0; m < M; m++) {
			v[m] += bool((B[0]) & (1ll << m));
		}
		return;
	}

	// the starting offset
	for (int d = 0; d < D && d <= H; d++) {
		ll nxtH = (H - d) / D;
		vector<uint64_t> nxtB(size_t((d + (N-1)) / D + 1), ((1ll << M)-1));

		for (int i = 0; i < N; i++) {
			uint64_t msk = B[i];
			int off = gen[(i+d) % D];
			assert(0 <= off && off < M);
			msk = (msk >> off) | (msk << (M - off));
			nxtB[(i + d) / D] &= msk;
		}

		dfs(nxtB, nxtH);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> D >> M;
	for (int i = 0; i < D; i++) {
		cin >> gen[i];
	}
	assert(gen[0] == 0);

	int N;
	cin >> N;

	vector<uint64_t> B(N);
	for (int i = 0; i < N; i++) {
		int b; cin >> b; b++;
		B[i] = (1ll << b) - 1;
	}
	ll L, R;
	cin >> L >> R;
	// 0-index the things
	L--; R--;

	// half-open interval
	R++;
	assert(R - L >= N);

	assert(R-N > L-1);

	dfs(B, L - 1);
	for (auto& it : results) {
		for (ll& v : it.second) {
			v = -v;
		}
	}
	dfs(B, R - N);

	ll res = 0;

	for (auto& it : results) {
		vector<ll>& v = dfs2(it.first);
		for (int i = 0; i < M; i++) {
			res += v[i] * it.second[i];
		}
	}

	cout << res << '\n';

	return 0;
}