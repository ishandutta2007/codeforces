#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using ull = uint64_t;
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
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        sort(all(v));
        bool have02 = false;
        bool have1 = false;
        for (int i = 0; i < n; ++i) {
            have02 |= v[i] == 0 || v[i] == 2;
            have1 |= v[i] == 1;
        }
        bool good;
        if (!have1) good = true;
        else if (have02) good = false;
        else {
            good = true;
            for (int i = 0; i + 1 < n; ++i) {
                if (v[i] + 1 == v[i + 1])
                    good = false;
            }
        }
        cout << (good ? "YES\n" : "NO\n");
    }
}