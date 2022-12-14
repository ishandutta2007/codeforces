#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vi a(n);
    for (int& i : a) cin >> i;

    vi p(n);
    map<int, int> cnt1, cnt2;
    int cur = 0;
    rep(i, n) {
        cur ^= a[i];
        if (i & 1) cnt2[cur]++;
        else cnt1[cur]++;
        p[i] = cur;
    }
    
    ll ans = 0;
    rep(i, n - 1) {
        int tar = i ? p[i - 1] : 0;
        if (i & 1) ans += cnt1[tar], cnt2[p[i]]--;
        else ans += cnt2[tar], cnt1[p[i]]--;
    }

    cout << ans;
}