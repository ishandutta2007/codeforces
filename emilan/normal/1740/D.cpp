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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (auto &x : a) cin >> x;

    set<int> s;
    for (int i = k, p = 0; i > 0; i--) {
        if (s.count(i)) {
            s.erase(i);
        } else {
            for (; a[p] != i; p++) s.insert(a[p]);
            p++;
            if (SZ(s) > n * m - 4) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        if (solve()) cout << "yA";
        else cout << "tIdAk";
        cout << '\n';
    }
}