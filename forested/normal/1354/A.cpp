#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a <= b) {
        cout << b << "\n";
    } else {
        if (c <= d) {
            cout << -1 << "\n";
        } else {
            cout << ((a - b - 1) / (c - d) + 1) * c + b << "\n";
        }
    }
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
    return 0;
}