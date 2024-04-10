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
        vector<int> x(n);
        for (int& xi : x) cin >> xi;
        int ans = 0;
        for (int y = x[0] - 1; y <= x[0] + 1 and not ans; y += 1) {
            int pans = 1;
            for (int i = 0; i < n and pans; i += 1)
                if (abs(x[i] - y - i) > 1)
                    pans = 0;
            if (pans)
                ans = 1;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}