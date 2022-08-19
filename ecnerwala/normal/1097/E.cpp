#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e5;
int N;
int A[MAXN];
vector<vector<int>> results;

int L;
vector<pair<int, int>> best[MAXN]; // best is increasing
int prv[MAXN];

vector<int> lis() {
	assert(N);
	L = 0;
	for (int i = 0; i < N; i++) {
		int mi = -1;
		int ma = L;
		while (ma - mi > 1) {
			int md = (mi + ma) / 2;
			assert(best[md].back().first != A[i]);
			if (best[md].back().first < A[i]) {
				mi = md;
			} else {
				ma = md;
			}
		}
		prv[i] = (mi == -1 ? -1 : best[mi].back().second);
		best[ma].emplace_back(A[i], i);
		L = max(L, ma+1);
	}
	assert(L);
	int cur = best[L-1].back().second;
	vector<int> res;
	while (cur != -1) {
		res.push_back(A[cur]);
		assert(cur > prv[cur]);
		cur = prv[cur];
	}
	reverse(res.begin(), res.end());
	assert(int(res.size()) == L);
	return res;
}

void go() {
	results.clear();
	while (N) {
		vector<int> a = lis();
		long long sz = (long long)a.size();

		if (sz * (sz + 1) / 2 <= N) {
			// Lower bound is at least sz
			for (int i = 0; i < sz; i++) {
				vector<int> r;
				for (auto it : best[i]) {
					r.push_back(it.first);
				}
				results.push_back(r);
				best[i] = {};
			}
			N = 0;
			break;
		} else {
			for (int i = 0; i < sz; i++) {
				best[i] = {};
			}
		}

		results.push_back(a);
		assert(sz * (sz+1) / 2 > N);
		assert(!a.empty());
		auto it = a.begin();
		int M = 0;
		for (int i = 0; i < N; i++) {
			int v = A[i];
			if (it != a.end() && v == *it) {
				// skip A[i]
				it++;
			} else {
				assert(M <= i);
				A[M] = v;
				M++;
			}
		}
		N = M;
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		go();
		cout << results.size() << '\n';
		for (const vector<int>& v : results) {
			cout << v.size();
			for (int i : v) {
				cout << ' ' << i;
			}
			cout << '\n';
		}
	}

	return 0;
}