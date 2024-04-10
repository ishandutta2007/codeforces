#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1000 * 1000 * 1000 + 7;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

const int MAXN = 1e5 + 7;

int cnt[4], ans[4];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    for (char c : s) {
        if (c == 'A') ++cnt[0];
        else if (c == 'C') ++cnt[1];
        else if (c == 'G') ++cnt[2];
        else ++cnt[3];
    }
    
    int mx = -1;
    for (int i = 0; i < 4; ++i) mx = max(mx, cnt[i]);
    int b = 0;
    for (int i = 0; i < 4; ++i) b += (cnt[i] == mx);
    
    int ans = 1;
    for (int i = 0; i < n; ++i) ans = mod(ans * b);
    cout << ans << '\n';

    return 0;
}