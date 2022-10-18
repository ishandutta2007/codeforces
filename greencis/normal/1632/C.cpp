//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int a, b;
        cin >> a >> b;
        int ans = b - a;
        int cur = 0;
        int z = 4 * b;
        for (int bb = b; cur < z; ++bb, ++cur) {
            int ored = a | bb;
            int needB = ored ^ bb;
            ans = min(ans, cur + 1 + needB);
        }
        cur = 0;
        for (int aa = a; cur < z; ++aa, ++cur) {
            int ored = aa | b;
            int needB = ored ^ b;
            ans = min(ans, cur + 1 + needB);
        }
        cout << ans << '\n';
    }
}