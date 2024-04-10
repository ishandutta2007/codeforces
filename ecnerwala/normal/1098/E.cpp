#include<bits/stdc++.h>
using namespace std;

namespace from_neal {
// Counts x, y >= 0 such that Ax + By <= C.
long long count_triangle(long long A, long long B, long long C) {
	if (C < 0) return 0;
	if (A > B) swap(A, B);
	long long p = C / B;
	long long k = B / A;
	long long d = (C - p * B) / A;
	return count_triangle(B - k * A, A, C - A * (k * p + d + 1)) + (p + 1) * (d + 1) + k * p * (p + 1) / 2;
}
}

using ll = long long;

const int MAXV = 1.1e5;
const int V = int(1e5) + 20;

const int MAXN = 5.5e4;
ll N;
int A[MAXN];
pair<int, int> dp1[MAXV]; // last occurrence of this factor, and how many times it occurs
vector<int> factors[MAXV];

ll bcnt[MAXV];

ll remcnt(ll rem, ll a, ll b) {
	return from_neal::count_triangle(a, b, rem - a - b);

	if (rem <= 0) return 0;
	assert(a > 0);
	assert(b > 0);
	ll g = __gcd(a, b);
	a /= g;
	b /= g;
	rem /= g;
	g = __gcd(a, b);
	assert(g == 1);

	if (rem < a + b) {
		return 0;
	}

	/*
	ll res = 0;
	for (ll i = 1; i * a <= rem; i++) {
		res += (rem - (i * a)) / b;
	}
	return res;
	*/

	if (rem >= a * b) {
		ll blocks = rem / a / b;
		ll block1val = rem - (a * (b + 1) + (b-1)) / 2;
		ll blockNval = block1val - (blocks - 1) * a * b;
		return blocks * (block1val + blockNval) / 2 + remcnt(rem - blocks * a * b, a, b);
	}
	assert(rem < a * b);
	if (a < b) swap(a, b);
	assert(a >= b);
	if (b == 1) {
		assert(rem < a);
		return 0;
	}
	assert(b > 1);
	assert(a > b);

	ll res = 0;
	for (ll v = rem - a; v > 0; v -= a) {
		res += v / b;
	}
	return res;
}

ll cnt(ll val) {
	ll ans = 0;
	// everything fully inside
	for (ll l = 1, r = 1, sum = 0, cnt = 0; r <= V; r++) {
		// make sure that it's not quite attainable
		while (l > 1 && sum <= val) {
			l--;
			cnt += bcnt[l];
			sum += bcnt[l] * l;
		}

		cnt += bcnt[r];
		sum += bcnt[r] * r;

		while (sum > val) {
			if (bcnt[l]) {
				// full l and full r are impossible
				// partial l and partial r may be possible tho
				if (l == r) {
					ll maxCnt = val / r;
					assert(maxCnt < bcnt[r]);
					ans += (bcnt[r] + (bcnt[r] - maxCnt + 1)) * maxCnt / 2;
				} else {
					ll rem = val - (sum - bcnt[l] * l - bcnt[r] * r);
					// rem = (val - sum) + bcnt[l] * l + bcnt[r] * r
					assert(bcnt[l] * l + bcnt[r] * r > rem);
					ans += remcnt(rem, l, r) - remcnt(rem - bcnt[l] * l, l, r) - remcnt(rem - bcnt[r] * r, l, r);
				}
			}

			cnt -= bcnt[l];
			sum -= bcnt[l] * l;
			l++;
		}

		assert(sum <= val);
		// ends anywhere inside r, starts somewhere earlier
		if (l < r) {
			ans += bcnt[r] * (cnt - bcnt[r]);
		}
		// starts and ends inside r
		if (l <= r) {
			ans += bcnt[r] * (bcnt[r] + 1) / 2;
		}
	}
	//cerr << val << ' ' << ans << '\n';
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	/*
	N = 5e4;
	for (int i = 0; i < N; i++) {
		A[i] = 1e5;
	}
	*/

	for (int i = 1; i <= V; i++) {
		for (int j = i; j <= V; j += i) {
			factors[j].push_back(i);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int f : factors[A[i]]) {
			if (dp1[f].first < i-1) {
				dp1[f].second = 1;
			} else {
				dp1[f].second ++;
			}
			dp1[f].first = i;
			bcnt[f] += dp1[f].second;
		}
	}

	for (int i = V; i >= 1; i--) {
		for (int j = i * 2; j <= V; j += i) {
			bcnt[i] -= bcnt[j];
		}
	}

	ll bsz = 0;
	ll bsum = 0;
	for (ll i = 1; i <= V; i++) {
		bsz += bcnt[i];
		bsum += i * bcnt[i];
	}
	assert(bsz == N * (N+1) / 2);

	//for (ll i = 1; i <= V; i++) { for (ll j = 0; j < bcnt[i]; j++) cerr << i << ' '; } cerr << '\n';

	// smallest v such that cnt(<= v) * 2 >= bsz * (bsz + 1) / 2
	ll mi = -1;
	ll ma = bsum + 1;
	while (ma - mi > 1) {
		ll md = (mi + ma) / 2;
		if (cnt(md) * 2 >= bsz * (bsz + 1) / 2) {
			ma = md;
		} else {
			mi = md;
		}
	}
	cout << ma << '\n';

	return 0;
}