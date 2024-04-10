#include <bits/stdc++.h>

using namespace std;

bool solve() {
    int n;
    string s;
    cin >> n >> s;
    return n == 1 || s == "01" || s == "10";
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