#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010], nxt[200010], tmp[200010], cnt[200010];
int b[200010];
void rmain() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], tmp[i] = -1, cnt[i] = 1;
    for (int i = n; i > 0; i--) {
        nxt[i] = tmp[a[i]];
        tmp[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1, j = 1; i <= n; i++) {
        while (a[j] != b[i]) {
            if (nxt[j] == -1) return cout << "NO\n", void();
            cnt[nxt[j]] += cnt[j];
            j++;
        }
        cnt[j]--;
        if (cnt[j] == 0) j++;
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) rmain();
}