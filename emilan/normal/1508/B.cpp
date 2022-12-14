#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

vector<int> solve() {
    int n;
    ll k;
    cin >> n >> k;
    k--;
    if (n <= 60 && k >= 1LL << (n - 1)) return {-1};

    vector<int> ans;
    for (int i = n - 1; i >= 61; i--) ans.push_back(n - i);

    for (int i = min(n - 1, 60), j = i; i >= 0; i--) {
        if (i == 0 || ~k >> (i - 1) & 1) {
            for (int p = i; p <= j; p++) ans.push_back(n - p);
            j = i - 1;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        auto ans = solve();
        for (int i = 0; i < SZ(ans); i++) {
            cout << ans[i] << " \n"[i == SZ(ans) - 1];
        }
    }
}