#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline long long nxt() {
	long long x;
	scanf("%lld", &x);
	return x;
}

int main() {
	int n = nxt(), m = nxt(), a = nxt();
	long long d = nxt();

	vector<long long> times(m);
	for (int i = 0; i < m; ++i) {
		times[i] = nxt();
	}

	long long ans = 0;
	long long num_as = d / a + 1;

	long long cur_n = 1;
	int cur_idx = 0;
	while (cur_n <= n && cur_idx < m) {
		if (times[cur_idx] < a * cur_n) {
			long long when_stops = times[cur_idx] + d;
			// cerr << "door closes at " << when_stops << "\n";
			ans += 1;
			while (cur_idx < m && times[cur_idx] <= when_stops) {
				++cur_idx;
			}
			cur_n = when_stops / a + 1;
		} else if (times[cur_idx] <= a * cur_n + d) {
			long long when_stops = a * cur_n + d;
			// cerr << "door closes at " << when_stops << "\n";
			ans += 1;
			while (cur_idx < m && times[cur_idx] <= when_stops) {
				++cur_idx;
			}
			cur_n = when_stops / a + 1;
		} else {
			long long cnt = min((n - cur_n + 1) / num_as, (times[cur_idx] - cur_n * a) / (num_as * a));
			// cerr << "erased " << cnt << "\n";
			if (cnt == 0) {
				long long when_stops = a * cur_n + d;
				// cerr << "door closes at " << when_stops << "\n";
				ans += 1;
				while (cur_idx < m && times[cur_idx] <= when_stops) {
					++cur_idx;
				}
				cur_n = when_stops / a + 1;
			} else {
				ans += cnt;
				cur_n += cnt * num_as;
			}
		}
	}

	if (cur_n <= n) {
		ans += (n - cur_n + 1 + num_as - 1) / num_as;
	}
	while (cur_idx < m) {
		long long when_stops = times[cur_idx] + d;
		ans += 1;
		while (cur_idx < m && times[cur_idx] <= when_stops) {
			++cur_idx;
		}
	}

	printf("%lld\n", ans);

	return 0;
}