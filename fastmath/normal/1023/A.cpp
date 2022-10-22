#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

bool used[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; 
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    
    int p = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
            p = i;
        }
    }

    if (p == -1) {
        if (s == t) {
            cout << "YES\n";
        }   
        else {
            cout << "NO\n";
        }
    }
    else {
        bool ans = 1;
        for (int i = 0; i < p; ++i) {
            ans &= (i < (int)t.size() && s[i] == t[i]);
            used[i] = 1;
        }
        for (int i = 0; i < n - p - 1; ++i) {
            int j = m - i - 1;
            if (j >= 0 && used[j]) ans = 0;
            ans &= (j >= 0 && s[n - i - 1] == t[j]);
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}