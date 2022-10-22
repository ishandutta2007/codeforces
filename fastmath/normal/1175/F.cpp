#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
int n;
int a[N];
int cnt[N];
int rr[N];
bool check(int l, int r) {
    return r <= rr[l];
}   
int ans = 0;
int mn[N], mx[N];
void solve(int l, int r) {
    if (l == r) {
        ans += a[l] == 1;
        return;
    }   

    int m = (l + r) >> 1;
    solve(l, m); solve(m + 1, r);

    int t = INF;
    for (int i = m; i >= l; --i) {
        t = min(t, a[i]);
        mn[i] = t;
    }   
    t = INF;
    for (int i = m + 1; i <= r; ++i) {
        t = min(t, a[i]);
        mn[i] = t;
    }   

    t = -INF;
    for (int i = m; i >= l; --i) {
        t = max(t, a[i]);
        mx[i] = t;
    }
    t = -INF;
    for (int i = m + 1; i <= r; ++i) {
        t = max(t, a[i]);
        mx[i] = t;
    }   

    int len = -1;
    for (int i = m; i >= l; --i) {
        len = max(len, a[i]);
        int r1 = i + len - 1;
        ans += r1 > m && r1 <= r && check(i, r1) && min(mn[i], mn[r1]) == 1 && max(mx[i], mx[r1]) == len;
    }   

    len = -1;
    for (int i = m + 1; i <= r; ++i) {
        len = max(len, a[i]);
        int l1 = i - len + 1;
        ans += l1 <= m && l1 >= l && check(l1, i) && min(mn[l1], mn[i]) == 1 && max(mx[l1], mx[i]) == len;
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int r = -1;
    for (int l = 0; l < n; ++l) {
        if (l) {
            --cnt[a[l - 1]];
        }   
        while (r + 1 < n && !cnt[a[r + 1]]) {
            ++r;
            ++cnt[a[r]];
        }   
        rr[l] = r;
    }
    solve(0, n - 1);
    cout << ans << '\n';
}