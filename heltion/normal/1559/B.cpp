#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        string s;
        cin >> n >> s;
        for (int i = 0; i < n; i += 1)
            if (s[i] == '?' and i and s[i - 1] != '?')
                s[i] = 'R' ^ 'B' ^ s[i - 1];
        if (s.back() == '?') s.back() = 'R';
        for (int i = n - 2; i >= 0; i -= 1)
            if (s[i] == '?') s[i] = 'R' ^ 'B' ^ s[i + 1];
        cout << s << "\n";
    }
    return 0;
}