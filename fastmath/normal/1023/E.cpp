#include <bits/stdc++.h>

using namespace std;

bool get(int x1, int y1, int x2, int y2) {
    cout << '?' << ' ' << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << '\n';
    fflush(stdout);
    string ans;
    cin >> ans;
    return (ans == "YES");
}

const int MAXN = 507;

vector <char> l, r;

signed main() {
    int n;
    cin >> n;
    
    int cx = 0, cy = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (get(cx + 1, cy, n - 1, n - 1)) {
            ++cx;
            l.push_back('D');
        }
        else {
            ++cy;
            l.push_back('R');
        }
    }

    cx = n - 1, cy = n - 1;
    for (int i = 0; i < n - 1; ++i) {
        if (get(0, 0, cx, cy - 1)) {
            --cy;
            r.push_back('R');
        }
        else {
            --cx;
            r.push_back('D');
        }
    }

    cout << "! ";
    for (auto el : l) cout << el;
    reverse(r.begin(), r.end());
    for (auto el : r) cout << el;
    cout << '\n';
    fflush(stdout);

    return 0;
}