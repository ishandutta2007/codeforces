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
        ll sum = 0;
        ll odd = 0;
        ll ones = 0;
        for (int i = 1; i + 1 < n; ++i) {
            sum += v[i] / 2;
            odd += v[i] % 2;
            ones += v[i] == 1;
        }
        if (ones == n - 2 || (n == 3 && odd == 1)) cout << "-1\n";
        else {
            cout << sum + odd << '\n';
        }
    }
}