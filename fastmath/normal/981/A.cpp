#include <bits/stdc++.h>

using namespace std;

bool ch(string s) {
    bool ch = true;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        ch &= (s[i] == s[n - i - 1]);
    }
    return ch;
}

signed main()
{
    //freopen("1.txt", "r", stdin);

    string s;
    cin >> s;

    int n = s.size();
    int ans = 0;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            if (!ch(s.substr(l, r - l + 1))) ans = max(ans, r - l + 1);
        }
    }

    cout << ans << '\n';
    return 0;
}