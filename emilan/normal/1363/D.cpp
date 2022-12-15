#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

void solve(int tc) {
    int n, k;
    cin >> n >> k;
    vt<vt<int>> s(k);
    for (auto &i : s) {
        int c;
        cin >> c;
        while (c--) {
            int x;
            cin >> x;
            i.push_back(x);
        }
    }

    cout << "? " << n;
    for (int i = 1; i <= n; i++) cout << ' ' << i;
    cout << endl;

    int mx;
    cin >> mx;

    int l = 0, r = k - 1;
    while (r - l + 1 > 2) {
        int mi = (l + r) / 2;

        vt<bool> indices(n + 1);
        for (int i = l; i <= mi; i++) {
            for (int j : s[i]) indices[j] = true;
        }
        vt<int> send;
        for (int i = 1; i <= n; i++) {
            if (indices[i]) send.push_back(i);
        }

        cout << "? " << sz(send);
        for (int i : send) cout << ' ' << i;
        cout << endl;

        int res;
        cin >> res;

        int js = 1 << __lg(r - l);
        if (res == mx) r = l + js - 1;
        else l = r - js + 1;
    }
    if (l != r) r = l + 1;

    auto get = [&](int x) {
        vt<bool> indices(n + 1, true);
        indices[0] = false;
        for (int i : s[x]) indices[i] = false;
        vt<int> send;
        for (int i = 1; i <= n; i++) {
            if (indices[i]) send.push_back(i);
        }
        
        cout << "? " << sz(send);
        for (int i : send) cout << ' ' << i;
        cout << endl;

        int ret;
        cin >> ret;
        return ret;
    };
    vt<int> ans(k, mx);
    ans[l] = get(l);
    ans[r] = get(r);

    cout << '!';
    for (int i : ans) cout << ' ' << i;
    cout << endl;

    string verdict;
    cin >> verdict;
    if (verdict == "Incorrect") exit(0);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve(tc);
    }
}