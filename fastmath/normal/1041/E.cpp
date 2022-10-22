#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

int l[MAXN], r[MAXN];
int a[MAXN], cnt[MAXN];
int pos[MAXN];
bool used[MAXN];

int ans[MAXN];
int cnt1[MAXN];

int n;

void check() {
    int curr = -1;
    for (int i = n - 2; i >= 0; --i) {
        curr = max(curr, ans[i]);
        ++cnt1[curr];   
    }
    for (int i = 1; i < n; ++i) {
        if (cnt[i] != cnt1[i]) {
            cout << "NO\n";
            exit(0);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> l[i] >> r[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        if (l[i] != n && r[i] != n) {
            cout << "NO\n";
            return 0;
        }
        a[i] = l[i] ^ r[i] ^ n;
    }

    sort(a, a + n - 1);
    for (int i = 0; i < n - 1; ++i) ++cnt[a[i]];

    int u = -1;
    for (int i = n - 1; i >= 1; --i) {
        if (cnt[i]) {
            pos[i] = u + cnt[i];
            u = pos[i];
        }
    }

    for (int i = 1; i < n; ++i) {
        if (cnt[i]) used[pos[i]] = 1;
    }
        
    u = 0;
    for (int i = n - 1; i >= 1; --i) {
        if (!cnt[i]) {
            while (used[u]) ++u;
            pos[i] = u;
            used[u] = 1;
        }
    }

    for (int i = 1; i < n; ++i) {
        ans[pos[i]] = i;
    }

    check();

    cout << "YES\n";
    cout << n << ' ' << ans[0] << '\n';
    for (int i = 0; i < n - 2; ++i) {
        cout << ans[i] << ' ' << ans[i + 1] << '\n';
    }

    return 0;
}