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

vector<int> zFunction(const vector<int>& s) {
    int n = s.size();

    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        z[i] = max(min(z[i - l], r - i), 0);

        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
            ++z[i];

        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    
    if (n)
        z[0] = n;

    return z;
}

set<vector<int>> forb = {{0, 0, 1, 1}, {0, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}};

const int mmod = 1000000007;

const int N = 3333;
long long dp[N][N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		vector<int> b(a.begin(), a.begin() + i + 1);
		reverse(all(b));
		b = zFunction(b);
		int idx = max_element(b.begin() + 1, b.end()) - b.begin();
		int maxlen = idx < (int)b.size() ? b[idx] : 0;
		int pos = i - idx - maxlen + 1;
		for (int j = 1; j <= maxlen; ++j) {
			dp[i + 1 - j][i + 1] = dp[pos + maxlen - j][pos + maxlen];
		}

		int l = i - maxlen;
		while (l >= 0) {
			for (int len = 1; len <= 4; ++len) {
				if (l + len > i + 1) {
					continue;
				}
				vector<int> last(a.begin() + i + 1 - len, a.begin() + i + 1);
				if (len == 4 && forb.count(last)) {
					continue;
				}
				if (l + len == i + 1) {
					dp[l][i + 1] += 1;
					ans += 1;
				} else {
					dp[l][i + 1] += dp[l][i + 1 - len];
					dp[l][i + 1] %= mmod;
					// cerr << l << " " << r << " " << len << ": " << dp[l][len] << "\n";
					ans += dp[l][i + 1 - len];
				}
			}
			--l;
		}

		ans %= mmod;
		printf("%lld\n", ans);
	}

	return 0;
}