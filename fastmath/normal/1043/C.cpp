#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

bool ans[MAXN];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();

    int l = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a' && (i == n - 1 || s[i + 1] == 'b')) {
            ans[l] = 1;
            ans[i] = 1;
        }   
        if (s[i] == 'b') l = i;
    }

    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}