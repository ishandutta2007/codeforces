#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> d(n);
	for (int i = 0; i < n; ++i) {
		d[i] = nxt();
	}
	d.push_back(0);
	sort(all(d));
	reverse(all(d));
	vector<int> ids;
	for (int i = 0, idx = n; i < n; ++i) {
		while (idx > 0 && d[idx - 1] == i) {
			--idx;
		}
		++d[idx];
		ids.push_back(idx);
	}

	d.push_back(0);
	++n;
	d.erase(d.begin());
	vector<long long> p(n + 1);
	for (itn i = 0; i < n; ++i) {
		p[i + 1] = p[i] + d[i];
	}

	bool found = true;
	int l = 0, r = n;

	for (int k = 1; k < n; ++k) {
		long long initial = 1ll * k * (k - 1) - p[k];
		int fst_lk = lower_bound(all(d), k, greater<int>()) - d.begin();
		fst_lk = max(fst_lk, k);
		initial += p[n] - p[fst_lk] + 1ll * k * (fst_lk - k);

		int fst_left = lower_bound(all(ids), k - 1, greater<int>()) - ids.begin();
		int fst_rt = min(k, fst_left);

		// cerr << fst_rt << " " << fst_left << " --\n";

		long long need = max(0ll, -initial);
		if (fst_rt < need) {
			found = false;
			break;
		}
		int sl = need;
		initial += fst_rt;
		int sr = min<long long>(n, fst_left + initial + 1);
		// cerr << sl << " " << sr << "\n";

		l = max(l, sl);
		r = min(r, sr);
	}

	long long s = accumulate(all(d), 0ll);

	if (l % 2 != s % 2) {
		++l;
	}
	if (r % 2 == s % 2) {
		--r;
	}
	if (l >= r) {
		found = false;
	}
	if (!found) {
		cout << "-1\n";
		return 0;
	}
	for (int i = l; i < r; i += 2) {
		printf("%d ", i);
	}
	printf("\n");

	return 0;
}