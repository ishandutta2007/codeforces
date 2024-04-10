#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int n, K, ans, cur[maxn], tmp[maxn];
pair<int, int> pre[maxn][maxn];
bool f[maxn][maxn];

void solve(int i, int j) {
    if (!i) return;
    solve(i - 1, pre[i][j].first);
    int o = pre[i][j].second;
    cout << "?";
    memcpy(tmp, cur, sizeof(tmp));
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (tmp[i] && ++cnt <= o) {
        cout << " " << i, cur[i] ^= 1;
    }
    cnt = 0;
    for (int i = 1; i <= n; i++) if (!tmp[i] && ++cnt <= K - o) {
        cout << " " << i, cur[i] ^= 1;
    }
    cout << endl;
    int x;
    cin >> x, ans ^= x;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> K;
    f[0][0] = 1;
    for (int i = 1; i <= 500; i++) {
        for (int j = 0; j <= n; j++) if (f[i - 1][j]) {
            for (int k = 0; k <= min(K, j); k++) {
                if (n - j < K - k) continue;
                f[i][j - k + K - k] = 1;
                pre[i][j - k + K - k] = {j, k};
            }
        }
        if (f[i][n]) {
            solve(i, n);
            cout << "! " << ans << endl, exit(0);
        }
    }
    cout << "-1" << endl;
    return 0;
}