#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

ll solve() {
    ll n;
    cin >> n;

    n *= 2;
    int pow2 = __builtin_ctzll(n);
    n >>= pow2;

    if (n == 1) return -1;
    else if (1LL << pow2 > n) return n;
    else return 1LL << pow2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << solve() << '\n';
    }
}