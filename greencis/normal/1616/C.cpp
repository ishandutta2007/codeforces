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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        if (n <= 2) {
            cout << "0\n";
            continue;
        }
        int ans = n - 2;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int need = 0;
                for (int z = 0; z < n; ++z) {
                    int cur = (v[j] - v[i]) * (z - i);
                    if (cur % (j - i) != 0 || v[z] != v[i] + cur / (j - i))
                        ++need;
                }
                ans = min(ans, need);
            }
        }
        cout << ans << '\n';
    }
}