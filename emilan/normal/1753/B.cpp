#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using pii = pair<int, int>;

bool solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> freq(k);
    for (int x : a) if (x < k) {
        freq[x]++;
    }

    int f = 0;
    for (int x = 1; x < k; x++) {
        f += freq[x];
        if (f % (x + 1) != 0) return false;
        f /= x + 1;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (solve()) cout << "Yes\n";
    else cout << "No\n";
}