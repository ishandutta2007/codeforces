#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool v(char c) {
    return c == 'a' || c == 'o' || c == 'e' || c == 'i' || c == 'u';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s, t;
    cin >> s >> t;
    if ((int)s.size() != (int)t.size()) {
        cout << "No\n";
        exit(0);
    }
    for (int i = 0; i < (int)s.size(); ++i) {
        if (v(s[i]) != v(t[i])) {
            cout << "No\n";
            exit(0);
        }
    }
    cout << "Yes\n";
}