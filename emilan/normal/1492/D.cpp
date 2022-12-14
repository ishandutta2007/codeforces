#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, k;
    cin >> a >> b >> k;

    string w = string(b, '1') + string(a, '0');

    if (k == 0) {
        cout << "Yes\n";
        cout << w << '\n';
        cout << w << '\n';
    } else if (a == 0 || b == 1 || k >= a + b - 1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";

        string s = w, t = w;
        t[1] = '0';
        if (k + 1 < b) {
            s[k + 1] = '0';
            s[b] = t[b] = '1';
        } else {
            t[k + 1] = '1';
        }

        cout << s << '\n';
        cout << t << '\n';
    }
}