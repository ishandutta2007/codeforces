#include <bits/stdc++.h>
using namespace std;

int T, n;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        cin >> n >> s;
        string t = s;
        sort(t.begin(), t.end());
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] ^ t[i]) k++;
        }
        cout << k << '\n';
    }
    return 0;
}