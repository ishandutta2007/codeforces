#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int i, int j) {
           return a[i] < a[j];
        });
        vector<int> b(n);
        if (n % 2 == 0) {
            for (int i = 0; i < n; i += 2) {
                int g = __gcd(a[p[i + 1]], a[p[i]]);
                b[p[i]] = a[p[i + 1]] / g;
                b[p[i + 1]] = -a[p[i]] / g;
            }
        } else {
            for (int i = 3; i < n; i += 2) {
                int g = __gcd(a[p[i + 1]], a[p[i]]);
                b[p[i]] = a[p[i + 1]] / g;
                b[p[i + 1]] = -a[p[i]] / g;
            }
            b[p[0]] = a[p[1]] * a[p[2]];
            b[p[1]] = a[p[0]] * a[p[2]];
            b[p[2]] = -a[p[0]] * a[p[1]] * 2;
        }
        for (int i = 0; i < n; ++i) {
            cout << b[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}