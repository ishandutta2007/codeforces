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
    char c = 'a';
    string s;
    cin >> s;
    if (s[0] != 'a') {
        cout << "NO\n";
        exit(0);
    }
    for (auto d : s) {
        if (d <= c) continue;
        if (d != c + 1) {
            cout << "NO\n";
            exit(0);
        }
        ++c;
    }
    cout << "YES\n";
}