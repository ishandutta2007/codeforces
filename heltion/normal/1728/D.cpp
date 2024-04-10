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
        int L = 0, R = s.size() - 1;
        while (L <= R and s[L] == s[R]) {
            L += 1;
            R -= 1;
        }
        int draw = 1;
        for (int i = L; i < R; i += 2) 
            draw &= s[i] == s[i + 1];
        cout << (draw ? "Draw\n" : "Alice\n");
    }
}