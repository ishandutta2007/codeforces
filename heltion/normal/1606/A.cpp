#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        string s;
        cin >> s;
        s.back() = s[0];
        cout << s << "\n";
    }
    return 0;
}