#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<int> v(26);
        string t;
        for (int i = 0, j = 0; i < n and j < k; i += 1) {
            while (s[i] != 'a' and not v[s[i] - 'a'] and j < k) {
                v[s[i] - 'a'] = 1;
                s[i] -= 1;
                j += 1;
            }
        }
        for (char c : s) {
            while (v[c - 'a']) c -= 1;
            cout << c;
        }
        cout << "\n";
    }
}