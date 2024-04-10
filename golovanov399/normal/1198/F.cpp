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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solveSmall(const vector<int>& a) {
	int n = a.size();
	const int N = 1 << n;
	vector<int> dp(N);
	for (int mask = 1; mask < N; ++mask) {
		int b = __builtin_ctz(mask);
		dp[mask] = gcd(dp[mask ^ (1 << b)], a[b]);
	}
	for (int i = 1; i < N / 2; ++i) {
		if (dp[i] == 1 && dp[N - 1 - i] == 1) {
			printf("YES\n");
			for (int j = 0; j < n; ++j) {
				printf("%d ", ((i >> j) & 1) + 1);
			}
			printf("\n");
			return;
		}
	}
	printf("NO\n");
}

void factor(int x, vector<int>& ps) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			ps.push_back(i);
			while (x % i == 0) {
				x /= i;
			}
		}
	}
	if (x > 1) {
		ps.push_back(x);
	}
}

const int K = 9;
void solveLarge(const vector<int>& a) {
	int n = a.size();
	for (int it = 0; it < 10; ++it) {
		int u = rand() % n;
		int v = (u + rand() % (n - 1) + 1) % n;
		vector<int> primes, fp, sp;
		factor(a[u], fp);
		factor(a[v], sp);
		primes.insert(primes.end(), all(fp));
		primes.insert(primes.end(), all(sp));
		make_unique(primes);
		for (int& x : fp) {
			x = lower_bound(all(primes), x) - primes.begin();
		}
		for (int& x : sp) {
			x = lower_bound(all(primes), x) - primes.begin();
		}

		int sz = primes.size();
		set<int> indices;
		for (int i = 0; i < sz; ++i) {
			vector<int> good_ids;
			for (int j = 0; j < n; ++j) {
				if (j == u || j == v) {
					continue;
				}
				if (a[j] % primes[i]) {
					good_ids.push_back(j);
					if ((int)good_ids.size() == 2 * K) {
						break;
					}
				}
			}
			for (int id : good_ids) {
				indices.insert(id);
			}
		}

		int N = 1 << (fp.size() + sp.size());
		vector<array<int, 3>> dp(N, {{-1, -1, -1}});
		vector<char> reachable(N);
		reachable[0] = 1;
		for (int i : indices) {
			int andmask_fst = 0, andmask_snd = 0;
			for (int j = 0; j < (int)fp.size(); ++j) {
				if (a[i] % primes[fp[j]]) {
					andmask_fst |= 1 << j;
				}
			}
			for (int j = 0; j < (int)sp.size(); ++j) {
				if (a[i] % primes[sp[j]]) {
					andmask_snd |= 1 << j;
				}
			}
			andmask_snd <<= fp.size();

			for (int j = N - 1; j >= 0; --j) {
				if (!reachable[j]) {
					continue;
				}
				if (!reachable[j | andmask_fst]) {
					reachable[j | andmask_fst] = true;
					dp[j | andmask_fst] = {j, i, 1};
				}
				if (!reachable[j | andmask_snd]) {
					reachable[j | andmask_snd] = true;
					dp[j | andmask_snd] = {j, i, 2};
				}
			}
		}
		if (!reachable[N - 1]) {
			continue;
		}
		printf("YES\n");
		vector<int> ans(n, 1);
		ans[v] = 2;
		for (int i = N - 1; i > 0; i = dp[i][0]) {
			ans[dp[i][1]] = dp[i][2];
		}
		for (int x : ans) {
			printf("%d ", x);
		}
		printf("\n");
		return;
	}
	printf("NO\n");
}

int main() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	if (n <= 2 * (K + 1)) {
		solveSmall(a);
	} else {
		solveLarge(a);
	}

	return 0;
}