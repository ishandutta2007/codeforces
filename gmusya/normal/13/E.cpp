#include <iostream>
#include <vector>
#include <math.h>

#define endl '\n'

using namespace std;

vector <int> a, cnt, net;

int n, q, x;

void update(int pos, int val) {
	a[pos] = val;
	if (pos + val > n)
		a[pos] = n - pos;
	cnt[pos] = 1;
	net[pos] = a[pos] + pos;
	for (int cur_pos = pos; cur_pos / x == pos / x && cur_pos >= 0; cur_pos--) {
		if (a[cur_pos] + cur_pos == n || (a[cur_pos] + cur_pos) / x != cur_pos / x)
			continue;
		cnt[cur_pos] = cnt[a[cur_pos] + cur_pos] + 1;
		net[cur_pos] = net[a[cur_pos] + cur_pos];
	}
}

pair <int, int> query(int pos) {
	pair <int, int> ans;
	ans.second = 0;
	while (net[pos] != n) {
		ans.second += cnt[pos];
		ans.first = pos;
		pos = net[pos];
	}
	while (pos != n) {
		ans.second++;
		ans.first = pos;
		pos += a[pos];
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	a.resize(n + 1), cnt.resize(n + 1), net.resize(n + 1);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		if (a[i] + i > n)
			a[i] = n - i;
	x = ceil(sqrt(n));
	for (int i = 0; i < n; i++) {
		int j = i;
		while (j != n && j / x == i / x) {
			cnt[i]++;
			j += a[j];
		}
		net[i] = j;
	}
	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if (type == 0) {
			int pos, val;
			cin >> pos >> val;
			update(pos - 1, val);
		}
		if (type == 1) {
			int pos;
			cin >> pos;
			pair <int, int> ans = query(pos - 1);
			cout << ans.first + 1 << " " << ans.second << endl;
		}
	}
	return 0;
}