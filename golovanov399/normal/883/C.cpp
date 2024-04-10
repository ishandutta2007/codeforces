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
	long long f = nxt(), T = nxt(), t0 = nxt();
	vector<array<long long, 3>> a;
	for (int i = 0; i < 2; ++i) {
		long long cnt = nxt(), t = nxt(), p = nxt();
		if (t < t0) {
			a.push_back({cnt, t, p});
		}
	}
	if (f * t0 <= T) {
		puts("0");
		return 0;
	}
	if (a.empty()) {
		puts("-1");
		return 0;
	}
	long long ans = -1;

	if ((int)a.size() == 1) {
		for (int i = 0; i <= f; ++i) {
			long long cost = i * a[0][2];
			long long obt_bytes = min(a[0][0] * i, f);
			long long rem_bytes = max(0ll, f - obt_bytes);
			long long tm = a[0][1] * obt_bytes + t0 * rem_bytes;
			if (tm <= T) {
				if (ans == -1 || ans > cost) {
					ans = cost;
				}
			}
		}
	} else {
		if (a[0][1] > a[1][1]) {
			swap(a[0], a[1]);
		}
		long long cnt2 = f;
		long long ob2 = min(cnt2 * a[1][0], f);
		long long tm2 = ob2 * a[1][1];
		long long cost2 = cnt2 * a[1][2];
		for (int i = 0; i <= f; ++i) {
			long long cost1 = i * a[0][2];
			long long ob1 = min(a[0][0] * i, f);
			long long tm1 = ob1 * a[0][1];

			ob2 = min(cnt2 * a[1][0], f - ob1);
			tm2 = ob2 * a[1][1];
			cost2 = cnt2 * a[1][2];
			while (cnt2 > 0) {
				long long ncnt2 = cnt2 - 1;
				long long nob2 = min(ncnt2 * a[1][0], f - ob1);
				long long ntm2 = nob2 * a[1][1];
				long long ncost2 = ncnt2 * a[1][2];

				if (tm1 + ntm2 + (f - ob1 - nob2) * t0 <= T) {
					cnt2 = ncnt2;
					cost2 = ncost2;
					ob2 = nob2;
					tm2 = ntm2;
				} else {
					break;
				}
			}
			if (tm1 + tm2 + (f - ob1 - ob2) * t0 <= T) {
				long long cost = cost1 + cost2;
				if (ans == -1 || ans > cost) {
					ans = cost;
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}