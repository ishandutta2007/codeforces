#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;

int n, m, tmp;
int a[MAXN], b[MAXN];

void read() {
    cin >> n >> tmp;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> m >> tmp;
    for (int i = 0; i < m; ++i) cin >> b[i];
}

int ans = 2;

int get(int t) {
    unordered_map <int, int> cnt;
    for (int i = 0; i < n; ++i) {
        ++cnt[(a[i] + t) % (t << 1)];
    }
    for (int i = 0; i < m; ++i) {
        ++cnt[b[i] % (t << 1)];
    }
    for (auto e : cnt) ans = max(ans, e.second);
    return ans;
}

void solve() {
    for (int pw = 0; pw < 32; ++pw) {
        ans = max(ans, get(1 << pw));
    }
}

void print() {
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}