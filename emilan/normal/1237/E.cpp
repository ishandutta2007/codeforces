#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    int o = 1, e = 2;
    while (o < n && e < n) {
        tie(o, e) = make_pair(e * 2 + 1, o + e + 1);
    }

    cout << (o == n || e == n);
}