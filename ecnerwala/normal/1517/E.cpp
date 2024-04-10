#include <bits/stdc++.h>

const int64_t MOD = 998244353;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int64_t> A(N); for (auto& a : A) cin >> a;
		vector<int64_t> pref(N+1);
		vector<int64_t> pref2(N+2);
		for (int i = 0; i < N; i++) {
			pref[i+1] = pref[i] + A[i];
			pref2[i+2] = pref2[i] + A[i];
		}
		int64_t tot = pref[N];

		int64_t ans = 0;
		{
			int mi = -1;
			int ma = N+1;
			while (ma - mi > 1) {
				int md = (mi + ma) / 2;
				if (pref[md] * 2 > tot) ma = md;
				else mi = md;
			}
			assert(ma <= N);
			ans += N+1-ma;
		}

		for (int st = 0; st <= 1; st++) {
			for (int en = N; en >= N-1; en--) {
				if (en - st < 2) continue;

				for (int p_st = st+1; p_st < en; p_st++) {
					int mi = st;
					if ((mi & 1) != (p_st & 1)) mi--;
					int mi_orig = mi;
					int ma = p_st + 2;
					while (ma - mi > 2) {
						int md = mi + ((ma - mi) >> 2 << 1);
						assert((p_st & 1) == (md & 1));
						int64_t cnd = pref[st] + (pref[en] - pref[p_st]) + (pref2[p_st] - pref2[md]);
						if (cnd * 2 > tot) mi = md;
						else ma = md;
					}
					ans += (mi - mi_orig) / 2;
				}
			}
		}

		cout << ans % MOD << '\n';
	}

	return 0;
}

// Consider the runs of Cs and Ps
// Only the first run of Cs can be > 1, and only the last run of Ps can be > 1
// This is necessary and sufficient
//
// runs: P (good, +1), C (bad)
// PC - binary-search
// Otherwise, optional P in front and C in back, then C run + alternating PCPCPC... + P run