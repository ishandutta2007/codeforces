#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// #define TEST

#ifdef TEST
vector<int> orig = {1, 1, 1, 1};
vector<int> current = orig;
#endif

void answer(const vector<int>& a) {
#ifdef TEST
	assert(a == orig);
#else
	cout << "! ";
	for (int x : a) {
		cout << x;
	}
	cout << endl;
#endif
	exit(0);
}

int ask(int l, int r) {
#ifndef TEST
	cout << "? " << l + 1 << " " << r + 1 << endl;
	return nxt();
#else
	int ll = l, rr = r;
	if (rand() % 2) {
		ll = 0;
	} else {
		rr = (int)current.size() - 1;
	}
	for (int i = ll; i <= rr; ++i) {
		current[i] ^= 1;
	}
	return accumulate(all(current), 0);
#endif
}

int main() {
#ifndef TEST
	int n = nxt(), t = nxt();
#else
	int n = orig.size(), t = accumulate(all(orig), 0);
#endif
	if (n == 1) {
		answer({t});
	}

	if (n % 2 == 0) {
		int cnt = 0;
		vector<int> ans(n);
		for (int i = 0; i < n; ++i) {
			bool lr[2] = {false, false};
			int old = t;
			while (!lr[0] || lr[1]) {
				int s = ask(i, i);
				lr[(i ^ s ^ t ^ 1) & 1] ^= 1;
				t = s;
			}
			if (t == old - 1 + i - 2 * cnt) {
				ans[i] = 1;
				cnt = i - cnt;
			} else {
				ans[i] = 0;
				cnt = i - cnt + 1;
			}
		}
		answer(ans);
	}

	vector<int> ans(n);
	{
		bool lr[2] = {false, false};
		int old = t;
		while (!lr[0] || !lr[1]) {
			int s = ask(1, n - 1);
			lr[(s ^ t ^ 1) & 1] ^= 1;
			t = s;
		}
		if (t == old - 1) {
			ans[0] = 1;
		}
		while (lr[0] || lr[1]) {
			int s = ask(1, n - 1);
			lr[(s ^ t ^ 1) & 1] ^= 1;
			t = s;
		}
	}
	int cnt = ans[0];

	for (int i = 1; i < n; ++i) {
		bool lr[2] = {false, false};
		int old = t;
		while (!lr[0] || lr[1]) {
			int s = ask(i - 1, i);
			lr[(i ^ s ^ t ^ 1) & 1] ^= 1;
			t = s;
		}
		if (t == old - 1 + i - 2 * cnt) {
			ans[i] = 1;
			cnt = i - cnt;
		} else {
			ans[i] = 0;
			cnt = i - cnt + 1;
		}
	}
	answer(ans);

	return 0;
}