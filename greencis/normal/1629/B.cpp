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

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int l, r, k;
        cin >> l >> r >> k;
        int odds = (r + 1) / 2 - l / 2;
        bool good = (l == r ? l > 1 : odds <= k);
        cout << (good ? "YES\n" : "NO\n");
    }
}