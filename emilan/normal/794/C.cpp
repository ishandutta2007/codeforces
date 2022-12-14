#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string s, t;
    cin >> s >> t;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    int n = s.size();
    string a(n, '\0');

    int sl = 0, sr = (n + 1) / 2;
    int tl = sr, tr = n;
    int al = 0, ar = n;
    for (int i = 0; al < ar; i ^= 1) {
        if (tl == tr || s[sl] < t[tr - 1]) {
            if (i == 0) a[al++] = s[sl++];
            else a[al++] = t[--tr];
        } else {
            if (i == 0) a[--ar] = s[--sr];
            else a[--ar] = t[tl++];
        }
    }

    cout << a;
}