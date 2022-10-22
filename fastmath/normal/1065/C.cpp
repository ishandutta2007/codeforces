#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e9 + 7;
const int MAXN = 2e5 + 7;

int n, k;
int a[MAXN];
void read() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
}

int ans = 0;
int cnt[MAXN], sum[MAXN];
void solve() {
    int mn = INF;
    for (int i = 0; i < n; ++i) mn = min(mn, a[i]);
    for (int i = 0; i < n; ++i) a[i] -= mn;
    bool ch = 1;
    for (int i = 0; i < n; ++i) ch &= !a[i];
    if (ch) {
        cout << "0\n";
        exit(0);
    }
    for (int i = 0; i < n; ++i) cnt[a[i]]++;
    int curr = n;
    for (int i = 0; i < MAXN; ++i) {
        curr -= cnt[i];
        sum[i] = curr;
    }   

    int u = 0;
    int nsum = 0;
    while (u < MAXN) {
        while (u < MAXN && nsum + sum[u] <= k) {
            nsum += sum[u];
            ++u;
        }
        nsum = 0;
        ++ans;
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