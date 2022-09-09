#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; i += 1)
            if (s[i] == 'L' or s[i] == 'R') cout << s[i];
            else cout << (char)('D' ^ 'U' ^ s[i]);
        cout << "\n";
    }
    return 0;
}