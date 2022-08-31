#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; ll M; cin >> N >> M;
		vector<int> x(N), p(N), disc; disc.reserve(N * 3);
		for (int i = 0; i != N; ++i) {
			cin >> x[i] >> p[i];
			disc.push_back(x[i] - p[i]);
			disc.push_back(x[i]);
			disc.push_back(x[i] + p[i]);
		}
		sort(disc.begin(), disc.end());
		disc.erase(unique(disc.begin(), disc.end()), disc.end());
		auto getp = [&](int v) {
			return lower_bound(disc.begin(), disc.end(), v) - disc.begin();
		};
		int siz = disc.size();
		vector<int> cnt(siz);
		for (int i = 0; i != N; ++i) {
			int a = getp(x[i] - p[i]), b = getp(x[i]), c = getp(x[i] + p[i]);
			cnt[a] += 1; cnt[b] -= 2; cnt[c] += 1;
		}
		for (int i = 1; i != siz; ++i) cnt[i] += cnt[i - 1];
		vector<ll> sum(siz);
		for (int i = 1; i != siz; ++i) sum[i] = sum[i - 1] + cnt[i - 1] * ll(disc[i] - disc[i - 1]);
		bool fl = true;
		for (int i = 0; i != siz; ++i)
			if (sum[i] > M) { fl = false; break; }
		if (fl) {
			string s(N, '1');
			cout << s << '\n';
			continue;
		}
		ll X = -1e18, Y = -1e18;
		for (int i = 0; i != siz; ++i) {
			if (sum[i] > M) {
				ll xx = sum[i] - M, yy = disc[i];
				X = max(X, xx + yy);
				Y = max(Y, xx - yy);
			}
		}
		string s(N, '0');
		for (int i = 0; i != N; ++i) {
			ll xx = p[i], yy = x[i];
			if (X <= xx + yy && Y <= xx - yy) s[i] = '1';
		}
		cout << s << '\n';
	}

	return 0;
}