#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        LL n, k, b, s;
        cin >> n >> k >> b >> s;
        if (b * k > s or b * k + (k - 1) * n < s)
            cout << "-1\n";
        else {
            vector<LL> a(n);
            a[0] = b * k;
            s -= b * k;
            for (int i = 0; i < n; i += 1) {
                LL h = min(k - 1, s);
                a[i] += h;
                s -= h;
            }
            for (LL ai : a) cout << ai << " ";
            cout << "\n";
        }
    }
}