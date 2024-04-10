#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;

int a[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    string ans = "EASY\n";
    for (int i = 0; i < n; ++i) {
        if (a[i]) ans = "HARD\n";
    }

    cout << ans;
    return 0;
}