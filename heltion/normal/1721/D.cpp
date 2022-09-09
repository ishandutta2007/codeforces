#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int& ai : a) cin >> ai;
        for (int& bi : b) cin >> bi;
        int ans = 0;
        for (int i = 29; i >= 0; i -= 1) {
            ans |= 1 << i;
            vector<int> fa, fb;
            for (int ai : a)
                fa.push_back(ans & ai);
            for (int bi : b)
                fb.push_back(ans - (ans & bi));
            ranges::sort(fa);
            ranges::sort(fb);
            if (fa != fb) ans ^= 1 << i;
        }
        cout << ans << "\n";
    }
}