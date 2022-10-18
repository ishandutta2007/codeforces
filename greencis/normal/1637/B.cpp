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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int zeroes = 0;
            for (int j = i; j < n; ++j) {
                zeroes += v[j] == 0;
                ans += (j - i + 1) + zeroes;
            }
        }
        cout << ans << endl;
    }
}