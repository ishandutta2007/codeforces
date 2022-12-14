#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

const int maxn = 2e5;
int bit[maxn], n;

int get(int i) {
    int r = 0;
    for (; ~i; i = (i & (i + 1)) - 1) r += bit[i];
    return r;
}

void dec(int i) {
    for (; i < n; i |= i + 1) bit[i]--;
}

void solve() {
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        bit[i]++;
        if (int t = i | (i + 1); t < n) bit[t] += bit[i];
    }

    map<char, vt<int>> st;
    for (int i = 0; i < n; i++) {
        st[s[i]].push_back(i);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int p = st[s[i]].back();
        st[s[i]].pop_back();
        ans += n - i - get(p);
        dec(p);
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}