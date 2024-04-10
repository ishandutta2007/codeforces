#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

// do it backwards

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> right(n + 1, -1);
    for (int i = 0; i < n; i++) {
        right[a[i]] = max(right[a[i]], i);
    }

    int ans = n;
    int j = -1;
    int nxt_j = -1;
    for (int i = 0; i < n; i++) {
        if (i > j) {
            ans--;
            j = nxt_j;
        }
        nxt_j = max(nxt_j, right[a[i]]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}