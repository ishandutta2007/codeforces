#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

constexpr int MOD = 998244353;
constexpr int INV2 = (MOD + 1) / 2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int a = 0, b = 1;
    for (int i = 1; i <= n; ++i) {
        int c = (a + b) % MOD;
        a = b;
        b = c;
    }
    for (int i = 1; i <= n; ++i) {
        a = a * (ll)INV2 % MOD;
    }
    cout << a << endl;
}