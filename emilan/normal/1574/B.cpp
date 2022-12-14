#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool solve() {
    vector<int> f(3);
    int m;
    cin >> f[0] >> f[1] >> f[2] >> m;
    sort(f.begin(), f.end());

    if (f[0] + f[1] + f[2] - 3 < m) return false;

    f[2] -= m + 1;
    return f[0] + f[1] >= f[2];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << (solve() ? "yEs" : "nO") << '\n';
    }
}