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

vector<int> primes;
bool isPrime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

const int L = 5;
int key[L];
int mod[L];
const int N = 1111111;
long long h[L][N];
long long deg[L][N];

int getHash(int l, int r, int id) {
	return (h[id][r] - h[id][l] * deg[id][r - l] % mod[id] + mod[id]) % mod[id];
}

array<long long, L> getHashes(int l, int r) {
	array<long long, L> res;
	for (int i = 0; i < L; ++i) {
		res[i] = getHash(l, r, i);
	}
	return res;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(0);

	for (int mod = 1e9; (int)primes.size() < 100; ++mod) {
		if (isPrime(mod)) {
			primes.push_back(mod);
		}
	}
	for (int i = 0; i < L; ++i) {
		key[i] = 239 + rand() % 100 * 2;
		mod[i] = primes[rand() % (int)primes.size()];
	}

	for (int j = 0; j < L; ++j) {
		deg[j][0] = 1;
		for (int i = 1; i < N; ++i) {
			deg[j][i] = deg[j][i - 1] * key[j] % mod[j];
		}
	}

	string s, t;
	cin >> s >> t;
	for (int j = 0; j < L; ++j) {
		for (int i = 0; i < (int)t.length(); ++i) {
			h[j][i + 1] = (h[j][i] * key[j] + t[i]) % mod[j];
		}
	}

	int cnt[2] = {0, 0};
	for (char c : s) {
		cnt[c - '0'] += 1;
	}

	int ans = 0;
	int n = t.length();
	for (int len0 = 1; len0 < n; ++len0) {
		if (1ll * len0 * cnt[0] >= n) {
			break;
		}
		if ((n - cnt[0] * len0) % cnt[1]) {
			continue;
		}
		int len1 = (n - cnt[0] * len0) / cnt[1];

		array<long long, L> hh[2];
		char used[2] = {0, 0};
		int off = 0;
		bool ok = true;
		for (char c : s) {
			array<long long, L> hm;
			if (c == '0') {
				hm = getHashes(off, off + len0);
				off += len0;
			} else {
				hm = getHashes(off, off + len1);
				off += len1;
			}
			if (used[c - '0']) {
				if (hm != hh[c - '0']) {
					ok = false;
					break;
				}
			} else {
				used[c - '0'] = 1;
				hh[c - '0'] = hm;
			}
		}
		if (ok && (len0 != len1 || hh[0] != hh[1])) {
			++ans;
		}
	}

	cout << ans << "\n";

	return 0;
}