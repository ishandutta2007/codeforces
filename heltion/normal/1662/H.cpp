#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int w, l;
        cin >> w >> l;
        set<int> s = {1, 2};
        auto f = [&](int n) {
            for (int i = 1; i * i <= n; i += 1)
                if (n % i == 0) {
                    s.insert(i);
                    s.insert(n / i);
                }
        };
        f(gcd(w - 1, l - 1));
        f(gcd(w - 2, l));
        f(gcd(w, l - 2));
        cout << s.size();
        for (int si : s) cout << " " << si;
        cout << "\n";
    }
}