#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int n;

void cnt(vector <ll> &a, vector <ll> &lr, vector <ll> &rl, vector <ll> &pre) {
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	for (int i = 1; i <= n; i++) lr[i] = lr[i - 1] + a[i] * i;
	for (int i = n; i >= 0; i--) rl[i] = rl[i + 1] + a[i] * (n - i + 1);
}

int main() {
	cin >> n;
	vector <ll> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	vector <ll> a_lr(n + 2), a_rl(n + 2), a_pre(n + 2), b_lr(n + 2), b_rl(n + 2), b_pre(n + 2);
	cnt(a, a_lr, a_rl, a_pre), cnt(b, b_lr, b_rl, b_pre);
	ll cursum = 0, answer = 0;
	for (int it = 0; it < 2 * n; it++) {
		int cur_x = it / 4 * 2 + 1, cur_y = 1;
		if (it % 4 == 1) cur_y++;
		if (it % 4 == 2) cur_x++, cur_y++;
		if (it % 4 == 3) cur_x++;
		if (cur_y == 1) cursum += a[cur_x] * (it + 1);
		if (cur_y == 2) cursum += b[cur_x] * (it + 1);
		if (it % 2) continue;
		ll tmp = 0;
		if (cur_y == 1) {
			ll sumonsega = a_pre[n] - a_pre[cur_x];
			ll sumonsegb = b_pre[n] - b_pre[cur_x - 1];
			tmp += (a_lr[n] - a_lr[cur_x]) + sumonsega * (it + 1 - cur_x);
			tmp += b_rl[cur_x] + sumonsegb * (n + cur_x - 1);
		}
		if (cur_y == 2) {
			ll sumonsegb = b_pre[n] - b_pre[cur_x];
			ll sumonsega = a_pre[n] - a_pre[cur_x - 1];
			tmp += (b_lr[n] - b_lr[cur_x]) + sumonsegb * (it + 1 - cur_x);
			tmp += a_rl[cur_x] + sumonsega * (n + cur_x - 1);
		}
		answer = max(answer, cursum + tmp);
	}
	cout << answer - (a_pre[n] + b_pre[n]);
	return 0;
}