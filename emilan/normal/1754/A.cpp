#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int q = 0;
    for (auto c : s) {
        if (c == 'Q') q++;
        else q = max(q - 1, 0);
    }

    if (q == 0) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}