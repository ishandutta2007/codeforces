#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

// #define TEST

#ifdef TEST
int g_n;
vector<int> g_t;
#endif

int ask(int x, int y, int z) {
#ifdef TEST
	return (g_t[x] + g_t[y] + g_t[z]) / 2;
#else
	cout << "? " << x + 1 << " " << y + 1 << " " << z + 1 << endl;
	return nxt();
#endif
}

void solve() {
#ifdef TEST
	int n = g_n;
#else
	int n = nxt();
#endif
	const int k = n / 3;
	vector<int> maj(k);
	for (int i = 0; i < k; ++i) {
		maj[i] = ask(3 * i, 3 * i + 1, 3 * i + 2);
	}

	vector<int> type(n, -1);
	vector<int> sum(k);
	for (int i = 0; i < k; ++i) {
		sum[i] = maj[i] * 3;
	}

	int canonical[2] = {-1, -1};
	for (int i = 0; i < k; ++i) {
		canonical[maj[i]] = i;
	}

	auto find_out = [&](int what, int by) {
		int need = 3 * by;
		while (type[need] != maj[by]) {
			++need;
		}
		int q[3];
		for (int i = 0; i < 3; ++i) {
			q[i] = 3 * what + i;
		}
		vector<int> cands;
		for (int i = 0; i < 2; ++i) {
			q[i] = need;
			if (ask(q[0], q[1], q[2]) == maj[by]) {
				sum[what] = maj[what] + 1;
				type[3 * what + i] = !maj[by];
			} else {
				cands.push_back(3 * what + i);
			}
			q[i] = 3 * what + i;
		}
		if (sum[what] % 3) {
			for (int x : cands) {
				type[x] = maj[by];
			}
		}
		int x = sum[what];
		for (int i = 0; i < 3; ++i) {
			if (~type[3 * what + i]) {
				x -= type[3 * what + i];
			}
		}
		for (int i = 0; i < 3; ++i) {
			if (type[3 * what + i] == -1) {
				type[3 * what + i] = !!x;
			}
		}
	};

	// resolve both canonicals
	int c0 = canonical[0], c1 = canonical[1];
	for (int i = 0; i < 3; ++i) {
		int q[3], w[3];
		for (int j = 0; j < 3; ++j) {
			q[j] = 3 * c0 + j;
			w[j] = 3 * c1 + j;
		}
		swap(q[i], w[i]);
		if (ask(q[0], q[1], q[2]) != maj[c0]) {
			type[3 * c0 + i] = maj[c0];
			type[3 * c1 + i] = maj[c1];
			sum[c0] = maj[c0] + 1;
		}
		if (ask(w[0], w[1], w[2]) != maj[c1]) {
			type[3 * c0 + i] = maj[c0];
			type[3 * c1 + i] = maj[c1];
			sum[c1] = maj[c1] + 1;
		}
	}

	for (int c : {c0, c1}) {
		if (sum[c] % 3 == 0) {
			for (int i = 0; i < 3; ++i) {
				type[3 * c + i] = maj[c];
			}
		}
	}
	for (int it = 0; it < 3; ++it) {
		for (int c : {c0, c1}) {
			int cnt = 0;
			int x = sum[c];
			for (int i = 0; i < 3; ++i) {
				if (type[3 * c + i] == -1) {
					++cnt;
				} else {
					x -= type[3 * c + i];
				}
			}
			if (cnt == 1) {
				for (int i = 0; i < 3; ++i) {
					if (type[3 * c + i] == -1) {
						type[3 * c + i] = x;
					}
				}
			}
		}
		for (int i = 0; i < 3; ++i) {
			if ((type[3 * c0 + i] == -1) != (type[3 * c1 + i] == -1)) {
				int x = type[3 * c0 + i] == -1 ? type[3 * c1 + i] : type[3 * c0 + i];
				type[3 * c0 + i] = type[3 * c1 + i] = x;
			}
		}
	}
	{
		vector<int> unk[2];
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (type[3 * canonical[i] + j] == -1) {
					unk[i].push_back(3 * canonical[i] + j);
				}
			}
		}
		assert((unk[0].empty() && unk[1].empty()) || (unk[0].size() == 2u && unk[1].size() == 2u));
		if (unk[0].size() == 2u && unk[1].size() == 2u) {
			int q[3];
			for (int i = 0; i < 3; ++i) {
				q[i] = 3 * c0 + i;
			}
			q[unk[0][0] % 3] = unk[1][1];
			if (ask(q[0], q[1], q[2]) == maj[c0]) {
				type[unk[0][0]] = type[unk[1][0]] = maj[c1];
				type[unk[0][1]] = type[unk[1][1]] = maj[c0];
			} else {
				type[unk[0][0]] = type[unk[1][0]] = maj[c0];
				type[unk[0][1]] = type[unk[1][1]] = maj[c1];
			}
		}
	}

	for (int i = 0; i < k; ++i) {
		if (~type[3 * i]) {
			continue;
		}
		find_out(i, canonical[!maj[i]]);
	}

	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (type[i] == 0) {
			ans.push_back(i);
		}
	}
#ifdef TEST
	if (type != g_t) {
		cout << "fail\n";
		cout << "guessed: " << g_n << "\n";
		for (int x : g_t) {
			cout << x << " ";
		}
		cout << "\n";
		cout << "your answer: ";
		for (int x : type) {
			cout << x << " ";
		}
		cout << "\n";
		exit(0);
	} else {
		cout << "ok\n";
	}
#else
	cout << "! " << ans.size();
	for (int x : ans) {
		cout << " " << x + 1;
	}
	cout << endl;
#endif
}

mt19937 rr;

int main() {
	int t = nxt();
	while (t--) {
#ifdef TEST
		g_n = 3 * (rand() % 5 + 2);
		g_t.assign(g_n, 0);
		int k = rand() % (g_n / 3 - 1) + g_n / 3 + 1;
		fill(g_t.begin(), g_t.begin() + k, 1);
		shuffle(all(g_t), rr);
#endif
		solve();
	}

	return 0;
}