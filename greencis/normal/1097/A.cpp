#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);

    string s, t;
    int ok = 0;
    cin >> s;
    for (int i = 0; i < 5; ++i) {
        cin >> t;
        ok |= (s[0] == t[0] || s[1] == t[1]);
    }
    cout << (ok ? "YES" : "NO");
}