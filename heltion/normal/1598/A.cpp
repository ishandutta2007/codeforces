#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        int ok = 1;
        for (int i = 0; i < n; i += 1) ok &= s[i] == '0' or t[i] == '0';
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}