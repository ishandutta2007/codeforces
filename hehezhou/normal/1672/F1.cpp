#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010], b[200010], cnt[200010];
vector <int> pos[200010];
void rmain() {
    cin >> n;
    for (int i = 1; i <= n; i++) cnt[i] = 0, pos[i].clear(), cin >> a[i];
    for (int i = 1; i <= n; i++) {
        pos[++cnt[a[i]]].push_back(i);
    }
    for (int i = 1; i <= n; i++) if (pos[i].size()) {
        sort(pos[i].begin(), pos[i].end(), [](int x, int y) {
            return cnt[a[x]] == cnt[a[y]] ? a[x] < a[y] : cnt[a[x]] < cnt[a[y]];
        });
        for (int j = 1; j < pos[i].size(); j++) b[pos[i][j]] = a[pos[i][j - 1]];
        b[pos[i][0]] = a[pos[i].back()];
    }
    for (int i = 1; i <= n; i++) cout << b[i] << " \n"[i == n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) rmain();
}