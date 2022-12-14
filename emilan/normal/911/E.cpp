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

#define die return void(cout << "-1\n")

void solve() {
    int n, k;
    cin >> n >> k;
    vt<int> a(k);
    for (int &x : a) cin >> x;

    vt<int> ans(n);
    copy(all(a), ans.begin());
    vt<int> s{-1};
    vt<bool> vis(n + 1);
    int x = 1;
    for (int i = 0; i < k; i++) {
        s.push_back(a[i]);
        vis[a[i]] = true;
        while (s.back() == x) {
            x++;
            s.pop_back();
        }
    }

    while (~s.back()) {
        vt<int> t;
        while (x < s.back()) {
            if (vis[x]) die;
            vis[x] = true;
            t.push_back(x);
            x++;
        }
        x++;
        s.pop_back();
        copy(rall(t), ans.begin() + k);
        k += sz(t);
    }

    vt<int> t;
    for (int i = k + 1; i <= n; i++) t.push_back(i);
    copy(rall(t), ans.begin() + k);

    for (int i : ans) cout << i << ' ';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}