#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        LL n;
        cin >> n;
        LL L = 1, R = n + 1;
        auto f = [&](LL n) {
            vector<LL> a(3);
            for (LL& ai : a)
                ai = n / 3;
            for (int i = 0; i < n % 3; i += 1)
                a[i] += 1;
            LL res = 0;
            for (int i = 0; i < 3; i += 1)
                for (int j = 0; j < 3; j += 1)
                    if (i != j)
                        res += a[i] * a[j];
            return res;
        };
        while (L < R) {
            LL M = (L + R) >> 1;
            if (f(M) >= n) R = M;
            else L = M + 1;
        }
        cout << L << "\n";
    }
}