#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        if (n == 2) {
            cout << "2\n";
            continue;
        }
        n %= 4;
        if (n == 0) {
            cout << "0\n";
        } else if (n == 1) {
            cout << "1\n";
        } else if (n == 2) {
            cout << "0\n";
        } else if (n == 3) {
            cout << "1\n";
        }
    }
}