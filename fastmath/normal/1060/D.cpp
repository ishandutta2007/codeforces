#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;

int n;
int l[MAXN], r[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
}

int ans = 0;
void solve() {
    sort(l, l + n);
    sort(r, r + n);
    for (int i = 0; i < n; ++i) ans += max(l[i], r[i]);          
}

void print() {
    cout << ans + n << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}