#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 1'000'000;
int lp[MAXN + 1];
ull h[MAXN + 1], f[MAXN + 1];

void init() {
    iota(lp + 1, lp + MAXN + 1, 1);
    for (int i = 2; i <= MAXN; ++i) {
        if (lp[i] == i) {
            for (int j = 2 * i; j <= MAXN; j += i) {
                if (lp[j] == j) {
                    lp[j] = i;
                }
            }
        }
    }
    mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 2; i <= MAXN; ++i) {
        if (lp[i] == i) {
            h[i] = gen();
        }
    }
    f[1] = 0;
    for (int i = 2; i <= MAXN; ++i) {
        f[i] = f[i / lp[i]] ^ h[lp[i]];
    }
    for (int i = 2; i <= MAXN; ++i) {
        f[i] ^= f[i - 1];
    }
}

vector<int> sorted(vector<int> v) {
    sort(all(v));
    return v;
}

vector<int> solve(int n) {
    ull total = 0;
    for (int i = 2; i <= n; ++i) {
        total ^= f[i];
    }
    if (total == 0) {
        return {};
    }
    for (int i = 2; i <= n; ++i) {
        if (total == f[i]) {
            return {i};
        }
    }
    unordered_map<ull, int> mp;
    for (int i = 2; i <= n; ++i) {
        mp[total ^ f[i]] = i;
    }
    for (int i = 2; i <= n; ++i) {
        auto it = mp.find(f[i]);
        if (it != mp.end()) {
            return sorted({i, it->second});
        }
    }
    for (int i = 2; i < n; ++i) {
        auto it = mp.find(f[i] ^ f[n]);
        if (it != mp.end()) {
            return sorted({i, it->second, n});
        }
    }
    return {-1}; // should not happen
}

void print(int n, const vector<int>& ans) {
    cout << n - ans.size() << '\n';
    for (int i = 1; i <= n; ++i) {
        if (find(all(ans), i) == ans.end()) {
            cout << i << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();

    int n;
    cin >> n;
    print(n, solve(n));
}