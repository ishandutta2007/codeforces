#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        string s;
        cin >> s;
        int ans = 1;
        for (int i = 0, j = 0; i < s.size() and ans; i = j) {
            while (j < s.size() and s[j] == s[i])
                j += 1;
            if (i + 1 == j)
                ans = 0;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}