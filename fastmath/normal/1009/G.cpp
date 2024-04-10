#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;
const int K = 6;

int n;
string s;
int mask[MAXN];
int cntl[K], cntr[1 << K];

void read() {
	cin >> s;
	n = s.size();

	for (int i = 0; i < n; ++i) {
		mask[i] = (1 << K) - 1;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int pos; cin >> pos; --pos;
	 	string t; cin >> t;
	 	mask[pos] = 0;
	 	for (char c : t) {
	 	 	mask[pos] ^= (1 << (c - 'a'));
	 	}
	}
}

bool check(int c) {
	bool ans = 1;

	--cntl[c];
	for (int m = 0; m < (1 << K); ++m) {
		int l = 0;
		for (int i = 0; i < K; ++i) {
		 	if ((m >> i) & 1) l += cntl[i];
	 	}

	 	int r = 0;
	 	for (int nm = 0; nm < (1 << K); ++nm) {
	 	 	if (m & nm) r += cntr[nm];
	 	}

	 	ans &= (l <= r);
	}
	++cntl[c];

	return ans;
}

void solve() {
	for (int i = 0; i < n; ++i) {
	    ++cntl[s[i] - 'a'];
	    ++cntr[mask[i]];
	}

	string ans = "";
	for (int i = 0; i < n; ++i) {
		--cntr[mask[i]];

		for (int c = 0; c < K; ++c) {
			if (!cntl[c]) continue;
			if (!((mask[i] >> c) & 1)) continue;
			if (check(c)) {
				--cntl[c];
			 	ans += (char)('a' + c);
			 	break;
			}
		}

		if ((int)ans.size() != i + 1) {
		 	cout << "Impossible\n";
		 	exit(0);
		}
	}

	cout << ans << '\n';
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	read();
	solve();

    return 0;
}