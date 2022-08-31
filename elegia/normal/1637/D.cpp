#include <bits/stdc++.h>

using namespace std;

const int _ = 205;

int a[_], b[_], w[_];
int d[_][_ * 2];

void chkmin(int& x, int y) { if (y < x) x = y; }

int balance(int N) {
	if (!N) return 0;
	int M = *max_element(w + 1, w + N + 1);
	int t = accumulate(w + 1, w + N + 1, 0) / 2;
	int A = 0, ret = 0;
	for (int i = 1; i <= N; ++i)
		if (t >= w[i]) {
			ret += w[i]; t += (w[i] *= -1);
			if (++A != i) swap(w[i], w[A]);
		}
	int inf = A + 1, B = N - A, *a = w, *b = w + A;
	for (int j = 0; j <= B; ++j) fill(d[j] + _ - M, d[j] + _ + M + 1, inf);
	d[0][_ - t] = 0;
	for (int j = 0; j <= B; ++j)
		for (int k = M; k >= -M; --k) {
			chkmin(d[j + 1][_ + k], d[j][_ + k]);
			if (k <= 0) chkmin(d[j + 1][_ + k + b[j + 1]], d[j][_ + k]);
			else for (int i = d[j][_ + k] + 1; i <= (j ? d[j - 1][_ + k] : inf - 1); ++i)
				chkmin(d[j][_ + k + a[i]], i);
		}
	int i = 0; while (d[B][_ + i] == inf) --i;
	return ret + t + i;
}

void solve() {
	int N; cin >> N;
	for (int i = 1; i <= N; ++i) cin >> a[i];
	for (int i = 1; i <= N; ++i) cin >> b[i];
	int cnt = 0, ans = 0, sum = 0, A = 0;
	for (int i = 1; i <= N; ++i) {
		if (a[i] > b[i]) swap(a[i], b[i]);
		if (b[i] > a[i]) w[++cnt] = b[i] - a[i];
		A += a[i]; sum += a[i] + b[i];
		ans += a[i] * a[i] + b[i] * b[i];
	}
	A += balance(cnt); int B = sum - A;
	ans = ans * (N - 2) + A * A + B * B;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}