#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (char c : s) {
        a += (c == '0');
        b += (c == '1');
    }   
    cout << abs(a - b) << '\n';

    return 0;
}