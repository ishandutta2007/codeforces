#include <bits/stdc++.h>
using namespace std;

int n;
string ans, tmp;

int main() {
    cin >> n;
    auto ask = [&](int r1, int c1, int r2, int c2) {
        cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
        string s; cin >> s;
        return s == "YES";
    };
    int r = 1, c = 1;
    while (n - r + n - c >= n) {
        if (r < n && ask(r + 1, c, n, n)) r++, ans.push_back('D');
        else c++, ans.push_back('R');
    }
    int r0 = n, c0 = n;
    while (r0 > r || c0 > c) {
        if (c0 > c && ask(1, 1, r0, c0 - 1)) c0--, tmp.push_back('R');
        else r0--, tmp.push_back('D');
    }
    reverse(tmp.begin(), tmp.end());
    ans.append(tmp);
    cout << "! " << ans << endl;
    return 0;
}