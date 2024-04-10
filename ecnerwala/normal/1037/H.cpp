#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int N;
string S;
int suffarr[MAXN]; // suffix array
int suffval[MAXN]; // inverse of the suffix array (value of each suffix)

vector<pair<int, int>> buckets1[MAXN];
vector<int> buckets2[MAXN];

void buildSuffixArray() {
	int V = 26;
	for (int i = 0; i < N; i++) {
		suffval[i] = S[i] - 'a';
	}
	// lcp is all 0
	for (int l = 1; l == 1 || l < N; l *= 2) {
		for (int i = 0; i < N; i++) {
			int v2 = (i + l >= N) ? -1 : suffval[i + l];
			assert(-1 <= v2 && v2 < V);
			buckets2[v2+1].push_back(i);
		}
		for (int v2 = -1; v2 < V; v2++) {
			for (int i : buckets2[v2+1]) {
				int v1 = suffval[i];
				assert(0 <= v1 && v1 < V);
				buckets1[v1].emplace_back(i, v2);
			}
			buckets2[v2+1].clear();
		}
		int NV = -1;
		pair<int, int> lastVal(-1, -1);
		for (int v1 = 0; v1 < V; v1++) {
			for (auto it : buckets1[v1]) {
				int i = it.first, v2 = it.second;
				assert(v1 == suffval[i]);
				pair<int, int> val(v1, v2);
				assert(val >= lastVal);
				if (val == lastVal) {
					assert(NV >= 0);
					suffval[i] = NV;
				} else {
					NV++;
					suffval[i] = NV;
					lastVal = val;
				}
			}
			buckets1[v1].clear();
		}
		V = NV+1;
	}
	assert(V == N);
	for (int i = 0; i < N; i++) {
		suffarr[i] = -1;
	}
	for (int i = 0; i < N; i++) {
		assert(0 <= suffval[i] && suffval[i] < N);
		assert(suffarr[suffval[i]] == -1);
		suffarr[suffval[i]] = i;
	}
}

const int NSEG = 1 << 17;
int seg[2*NSEG];

void segUpdate(int ind, int v) {
	//cerr << "segUpdate " << ind << ' ' << v << '\n';
	for (int i = ind + NSEG; i; i /= 2) {
		assert(v < seg[i]);
		seg[i] = v;
	}
}

// find the first guy <= v between [l, r)
int segQuery(int l, int r, int v) {
	//cerr << "segQuery " << l << ' ' << r << ' ' << v << '\n';
	int lcnd = -1;
	int rcnd = -1;
	for (int a = l + NSEG, b = r + NSEG; a < b; a /= 2, b /= 2) {
		if (a & 1) {
			if (seg[a] <= v) {
				if (lcnd == -1) {
					lcnd = a;
				}
			}
			a++;
		}
		if (b & 1) {
			b--;
			if (seg[b] <= v) {
				rcnd = b;
			}
		}
	}

	int cur;
	if (lcnd != -1) cur = lcnd;
	else if (rcnd != -1) cur = rcnd;
	else return -1;

	assert(seg[cur] <= v);
	while (cur < NSEG) {
		if (seg[2 * cur] <= v) {
			cur = 2 * cur;
		} else if (seg[2 * cur + 1] <= v) {
			cur = 2 * cur + 1;
		} else assert(false);
	}
	return cur - NSEG;
}

const int MAXQ = 2.1e5;
int Q;
using pii = pair<int, int>;
pair<pii, string> queries[MAXQ];
string res[MAXQ];

vector<int> lQueries[MAXN];
int main() {
	ios_base::sync_with_stdio(0);
	cin >> S;
	N = int(S.size());
	buildSuffixArray();

	//for (int i = 0; i < N; i++) { cerr << suffarr[i] << ' ' << S.substr(suffarr[i]) << '\n'; } cerr << '\n';

	cin >> Q;
	for (int q = 0; q < Q; q++) {
		int l, r; cin >> l >> r >> queries[q].second;
		l--, r--;
		queries[q].first = pii(l, r);
		lQueries[l].push_back(q);
	}

	for (int i = 2*NSEG-1; i > 0; i --) {
		seg[i] = N;
	}

	for (int l = N-1; l >= 0; l--) {
		// first update the seg tree
		{
			int ind = suffval[l];
			assert(suffarr[ind] == l);
			segUpdate(ind, l);
		}

		// now we do a query
		for (int q : lQueries[l]) {
			assert(l == queries[q].first.first);
			int r = queries[q].first.second;
			string& x = queries[q].second;
			//cerr << "query #" << q << ": " << l << ' ' << r << ' ' << x << '\n';
			int st = 0, en = N;
			int resind = -1;
			int reslen = -1;
			for (int i = 0; i <= int(x.size()); i++, r--) {
				char c = size_t(i) < x.size() ? x[size_t(i)] : -1;
				// we first binary search for the high point
				int mi = st-1, ma = en;
				while (ma - mi > 1) {
					int md = (mi + ma) / 2;
					char cnd = (suffarr[md] + i < N) ? S[suffarr[md] + i] : -1;
					if (cnd <= c) {
						mi = md;
					} else {
						ma = md;
					}
				}
				// ma is the first one > c
				int nen = ma;
				mi = st-1, ma = nen;
				while (ma - mi > 1) {
					int md = (mi + ma) / 2;
					char cnd = (suffarr[md] + i < N) ? S[suffarr[md] + i] : -1;
					if (cnd < c) {
						mi = md;
					} else {
						ma = md;
					}
				}
				// ma is the first one >= c
				int nst = ma;

				//cerr << st << ' ' << nst << ' ' << nen << ' ' << en << '\n';

				int v = segQuery(nen, en, r);
				if (v != -1) {
					resind = suffarr[v];
					reslen = i+1;
					assert(resind + reslen <= N);
				}

				st = nst, en = nen;
			}

			if (resind == -1) {
				res[q] = "-1";
			} else {
				res[q] = S.substr(resind, reslen);
			}
		}
	}

	for (int q = 0; q < Q; q++) {
		cout << res[q] << '\n';
	}

	return 0;
}