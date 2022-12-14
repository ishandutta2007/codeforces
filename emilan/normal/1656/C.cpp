#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

bool solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    sort(RALL(a));

    int cnt0 = count(ALL(a), 0);
    int cnt1 = count(ALL(a), 1);
    int cnt2 = count(ALL(a), 2);
    if (cnt1 == 0) return true;
    else if (cnt0 > 0 || cnt2 > 0) return false;
    else {
        for (int i = 0; a[i] > 1; i++) {
            if (a[i] == a[i + 1] + 1) return false;
        }
        return true;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << (solve() ? "yEs" : "nO") << '\n';
    }
}