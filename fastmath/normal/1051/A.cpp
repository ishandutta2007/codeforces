#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (char c : s) {
        cnt1 += ('0' <= c && c <= '9');
        cnt2 += ('a' <= c && c <= 'z');
        cnt3 += ('A' <= c && c <= 'Z');
    }

    int n = s.size();

    if (cnt1 && cnt2 && cnt3) {
        cout << s << '\n';
        return;
    }
    else if (cnt1 && cnt2) {
        if (1 < cnt1) {
            for (int i = 0; i < n; ++i) {
                if ('0' <= s[i] && s[i] <= '9') {
                    s[i] = 'A';
                    break;
                }
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                if ('a' <= s[i] && s[i] <= 'z') {
                    s[i] = 'A';
                    break;
                }
            }
        }
        cout << s << '\n';
        return;
    }
    else if (cnt2 && cnt3) {
        if (1 < cnt2) {
            for (int i = 0; i < n; ++i) {
                if ('a' <= s[i] && s[i] <= 'z') {
                    s[i] = '0';
                    break;
                }
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                if ('A' <= s[i] && s[i] <= 'Z') {
                    s[i] = '0';
                    break;
                }
            }
        }
        cout << s << '\n';
        return;
    }
    else if (cnt1 && cnt3) {
        if (1 < cnt1) {
            for (int i = 0; i < n; ++i) {
                if ('0' <= s[i] && s[i] <= '9') {
                    s[i] = 'a';
                    break;
                }
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                if ('A' <= s[i] && s[i] <= 'Z') {
                    s[i] = 'a';
                    break;
                }
            }
        }
        cout << s << '\n';
        return;
    }
    else if (cnt1) {
        s[1] = 'a';
        s[2] = 'A';
        cout << s << '\n';
        return;
    }
    else if (cnt2) {
        s[1] = '0';
        s[2] = 'Z';
        cout << s << '\n';
        return;
    }
    else if (cnt3) {
        s[1] = '0';
        s[2] = 'a';
        cout << s << '\n';
        return;
    }
    else {
        exit(1);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) solve();

    return 0;
}