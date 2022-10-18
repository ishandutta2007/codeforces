#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        ll a, b;
        cin >> a >> b;
        if ((a + b) % 2) {
            cout << "-1\n";
        } else {
            if (a > b) swap(a, b);
            if (a == 0 && b == 0)
                cout << "0\n";
            else if (a == b)
                cout << "1\n";
            else
                cout << "2\n";
        }
    }
}