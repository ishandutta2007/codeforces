#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using pii = pair<int, int>;

const int kA = 50;

bool solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    string s;
    cin >> s;

    array<set<char>, kA + 1> map_;
    for (int i = 0; i < n; i++) {
        map_[a[i]].insert(s[i]);
    }

    for (auto &v : map_) {
        if (SZ(v) >= 2) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}