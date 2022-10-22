#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 3e5 + 7;

int n;
int a[MAXN];

const int LEN = 64;

int pref[MAXN];
int cnt0 = 0, cnt1 = 0;
void add(int i) {
    if (i < -1) return;
    else if (i == -1) {
        ++cnt0;
    }
    else {
        if (pref[i + 1]) ++cnt1;
        else ++cnt0;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = __builtin_popcountll(a[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        int mx = -1;
        for (int len = 1; len < LEN && i + len - 1 < n; ++len) {
            int r = i + len - 1;
            sum += a[r];
            mx = max(mx, a[r]);
            ans += (sum % 2 == 0 && mx * 2 <= sum);
        }
    }

    for (int i = 0; i < n; ++i) {
        pref[i + 1] = (pref[i] + a[i]) % 2;
        add(i - LEN);
        if (pref[i + 1]) ans += cnt1;
        else ans += cnt0;
    }

    cout << ans << '\n';
    return 0;
}