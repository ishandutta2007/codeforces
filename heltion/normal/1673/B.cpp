#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        string s;
        cin >> s;
        set<char> sc;
        for (char c : s)
            sc.insert(c);
        int ok = 1;
        for (int i = 0; i < sc.size(); i += 1)
            for (int j = 0; j < i; j += 1)
                if (s[i] == s[j])
                    ok = 0;
        for (int i = 0; i < s.size(); i += 1)
            if (s[i] != s[i % sc.size()])
                ok = 0;
        cout << (ok ? "YES\n" : "NO\n");
    }
}