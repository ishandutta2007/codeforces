#include <bits/stdc++.h>
using namespace std;

int T, cnt[26];
string s;

int main() {
    cin >> T;
    while (T--) {
        cin >> s;
        memset(cnt, 0, sizeof(cnt));
        for (char c : s) cnt[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 1) cout << char(i + 'a');
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 1) cout << char(i + 'a');
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 1) cout << char(i + 'a');
        }
        cout << '\n';
    }
    return 0;
}