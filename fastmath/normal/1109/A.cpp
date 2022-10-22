#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 3e5 + 7;
int n;
int cnt[maxn];
int pref[maxn];
signed main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        pref[i + 1] = pref[i] ^ x;
    }
    map<int, int> have;
    have[0] = 1;
    int ans = 0;
    for (int i = 2; i <= n; i += 2) {
            if (have.count(pref[i]))
                ans += have[pref[i]];
            have[pref[i]]++;
    }
    have.clear();
    have[pref[1]] = 1;
    for (int i = 3; i <= n; i += 2) {
        if (have.count(pref[i]))
            ans += have[pref[i]];
        have[pref[i]]++;
    }
    cout << ans;
    return 0;
}