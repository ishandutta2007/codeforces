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
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        bool good = true;
        while (good) {
            good = false;
            for (int i = 0; i < n; ++i) {
                if (k >= a[i]) {
                    k += b[i];
                    a.erase(a.begin() + i);
                    b.erase(b.begin() + i);
                    --i;
                    --n;
                    good = true;
                }
            }
        }
        cout << k << '\n';
    }
}