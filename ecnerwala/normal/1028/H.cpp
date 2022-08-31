#include<bits/stdc++.h>
using namespace std;

const int MAXV = 6e6;
const int V = 5.1e6;
int pfac[MAXV];

const int MAXN = 2e5;
int N;
int A[MAXN];

const int MAXF = MAXN * 128;
int F;
int factors[MAXF];

void precomp() {
	for (int i = 0; i <= V; i++) {
		pfac[i] = i;
	}
	for (int i = 2; i * i <= V; i++) {
		if (pfac[i] != i) continue;
		for (int j = i * i; j <= V; j+=i) {
			pfac[j] = i;
		}
	}
}

vector<pair<int, int>> getFactors(int a) {
	assert(1 <= a && a <= V);
	vector<pair<int, int>> res;
	res.emplace_back(1, 0);
	int c = 0;
	while (a > 1) {
		int p = pfac[a];
		int e = 0;
		while (a % p == 0) {
			a /= p;
			e++;
		}
		assert(e);
		if (e & 1) {
			c++;
			size_t sz = size_t(res.size());
			res.reserve(sz * 2);
			for (size_t i = 0; i < sz; i++) {
				res.emplace_back(res[i].first * p, res[i].second + 1);
			}
		}
	}
	assert(c <= 7);
	for (auto& it : res) {
		it.second = c - it.second;
	}
	return res;
}

int lastf[MAXF][7 + 1];
int lastp[14 + 1];

const int MAXQ = 1.1e6;
int Q;
pair<pair<int, int>, int> queries[MAXQ];
int ans[MAXQ];

int main() {
	ios_base::sync_with_stdio(0);
	precomp();
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int q = 0; q < Q; q++) {
		int l, r; cin >> l >> r;
		assert(r - l + 1 >= 2);
		assert(1 <= l && l <= r && r <= N);
		queries[q].first = pair<int, int>(r, l);
		queries[q].second = q;
	}
	sort(queries, queries + Q);

	F = 0;
	for (int i = 1; i <= N; i++) {
		for (auto it : getFactors(A[i])) {
			factors[F++] = it.first;
		}
	}
	sort(factors, factors + F);
	F = int(unique(factors, factors + F) - factors);

	for (int i = 1, q = 0; i <= N; i++) {
		// insert A[i]
		for (auto it : getFactors(A[i])) {
			int f = int(lower_bound(factors, factors + F, it.first) - factors);
			int cost = it.second;
			assert(0 <= cost && cost <= 7);
			for (int c = 0; c <= 7; c++) {
				if (lastf[f][c] > 0) {
					lastp[cost + c] = max(lastp[cost + c], lastf[f][c]);
				}
			}
			lastf[f][cost] = i;
		}
		while (q < Q && queries[q].first.first <= i) {
			assert(queries[q].first.first == i);
			int l = queries[q].first.second;
			int res = -1;
			for (int c = 0; c <= 14; c++) {
				if (lastp[c] >= l) {
					res = c;
					break;
				}
			}
			assert(res != -1);
			ans[queries[q].second] = res;
			q++;
		}
	}

	for (int q = 0; q < Q; q++) {
		cout << ans[q] << '\n';
	}

	return 0;
}