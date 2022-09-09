#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        auto f = [&]() {
            int n;
            cin >> n;
            vector<int> v(n);
            for (int& vi : v) cin >> vi;
            return v;
        };
        auto a = f(), b = f();
        cout << a[reduce(b.begin(), b.end(), 0LL) % a.size()] << "\n";
    }
    return 0;
}