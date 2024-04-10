#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 5.1e5;
int N;
int A[MAXN];
const int MAXL = 5.1e5;
const int L = int(5e5) + 10;
int cnt[MAXL];
int pref[MAXL];
pair<int, int> last2[MAXL];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A,A+N);
	for (int i = 0; i < N; i++) {
		cnt[A[i]]++;
	}

	for (int l = 0; l <= L; l++) {
		pref[l+1] = pref[l] + cnt[l];
	}

	last2[0] = {0,0};
	for (int l = 1; l <= L; l++) {
		if (cnt[l] >= 2) {
			last2[l] = {l, l};
		} else if (cnt[l] == 1){
			last2[l] = {l, last2[l-1].first};
		} else {
			last2[l] = last2[l-1];
		}
	}

	int maxX = A[N-1] / 2;
	if (N >= 2) maxX = max(maxX, A[N-2]);

	ll ans = 0;
	for (int y = 2; y <= L; y++) {
		ll cntY = 0;
		for (int k = y; k <= L; k += y) {
			cntY += pref[L+1] - pref[k];
		}

		auto isGood = [&](int x) {
			if (x < 2) return true;
			ll cntY1 = 0;
			ll cntY2 = 0;
			for (int k = 0; k <= L; k += y) {
				auto vals = last2[min(k+y-1, L)];
				for (int z = 0; z < 2; z++) {
					int v = (z == 0 ? vals.first : vals.second);
					if (v < k) continue;
					if (v >= 2 * x) {
						cntY2 = max(cntY2, cntY - v / y + (v - (2 * x)) / y);
					}
					if (v >= x) {
						cntY2 = max(cntY2, cntY1 - v / y + (v - x) / y);
						cntY1 = max(cntY1, cntY - v / y + (v - x) / y);
					}
				}
			}
			return cntY2 >= x;
		};
		int cndX = int(min(ll(maxX), cntY - cntY / (y+1) * 2));
		int mi, ma;
		if (isGood(cndX)) {
			mi = cndX;
			for (int i = 0; true; i++) {
				if (isGood(cndX + (1<<i))) {
					mi = cndX + (1<<i);
				} else {
					ma = cndX + (1<<i);
					break;
				}
			}
		} else {
			ma = cndX;
			for (int i = 0; true; i++) {
				if (isGood(cndX - (1<<i))) {
					mi = cndX - (1<<i);
					break;
				} else {
					ma = cndX - (1<<i);
				}
			}
		}
		while (ma - mi > 1) {
			int md = mi + (ma - mi) / 2;
			if (isGood(md)) {
				mi = md;
			} else {
				ma = md;
			}
		}
		cndX = mi;
		if (cndX < 2) continue;
		ans = max(ans, 1ll * y * cndX);
	}
	cout << ans << '\n';

	return 0;
}