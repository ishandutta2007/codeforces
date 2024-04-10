#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> l(n), r(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        k -= l[i];
        r[i] -= l[i];
        sum += r[i];
    }
    if (k < 0 || k > sum)
        cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            int cur = min(k, r[i]);
            k -= cur;
            if (i) cout << ' ';
            cout << l[i] + cur;
        }
        cout << '\n';
    }
}