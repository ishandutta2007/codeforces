#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n + 1);
    vector<int> b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    int mex = 0;
    for (int i = 0; i < n; ++i) {
        if (!cnt[i]) {
            mex = i;
            break;
        }
    }
    map<int, int> _cnt;
    int now = 0;
    int _mex = mex;
    for (int i = 0; i < n; ++i) {
        ++_cnt[a[i]];
        while (_cnt[now]) {
            ++now;
        }
        --cnt[a[i]];
        if (!cnt[a[i]]) {
            _mex = min(_mex, a[i]);
        }
        // cout << now << ' ' << i << ' ' << mex << '\n';
        if (now == mex || i == n - 1) {
            b.push_back(now);
            now = 0;
            mex = _mex;
            _cnt = map<int, int> ();
        }
    }
    cout << b.size() << '\n';
    for (int i : b)
        cout << i << ' ';
    cout << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE
}