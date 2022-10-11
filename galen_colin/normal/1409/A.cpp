#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        int v = a - b;
        if (v < 0) v = -v;
        cout << (v + 9) / 10 << '\n';
    }
}