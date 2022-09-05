#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int T, n, a[maxn], lg[maxn];
long long pre[maxn], mn[2][20][maxn], mx[2][20][maxn];
vector<pair<long long, int>> Q[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (i & 1) a[i] *= -1;
            pre[i] = pre[i - 1] + a[i];
        }
        for (int i = 0; i <= n; i++) {
            Q[i].clear();
            if (i > 1) lg[i] = lg[i / 2] + 1;
        }
        for (int i : {0, 1}) for (int j = 0; j < 20; j++) {
            fill(mn[i][j], mn[i][j] + n + 1, 1e18);
            fill(mx[i][j], mx[i][j] + n + 1, -1e18);
        }
        for (int i = 0; i <= n; i++) {
            mn[i & 1][0][i] = min(mn[i & 1][0][i], pre[i]);
            mx[i & 1][0][i] = max(mx[i & 1][0][i], pre[i]);
        }
        for (int i : {0, 1}) for (int j = 1; j < 20; j++) {
            for (int k = 1; k + (1 << j) - 1 <= n; k++) {
                mn[i][j][k] = min(mn[i][j - 1][k], mn[i][j - 1][k + (1 << (j - 1))]);
                mx[i][j][k] = max(mx[i][j - 1][k], mx[i][j - 1][k + (1 << (j - 1))]);
            }
        }
        auto qmin = [&](int o, int l, int r) {
            int k = lg[r - l + 1];
            return min(mn[o][k][l], mn[o][k][r - (1 << k) + 1]);
        };
        auto qmax = [&](int o, int l, int r) {
            int k = lg[r - l + 1];
            return max(mx[o][k][l], mx[o][k][r - (1 << k) + 1]);
        };
        auto chk = [&](int l, int r) {
            bool flag = 1;
            if (l & 1) {
                flag &= qmax(1, l, r) - pre[l - 1] <= 0;
                flag &= qmin(0, l, r) - pre[l - 1] >= 0;
            } else {
                flag &= qmin(0, l, r) - pre[l - 1] >= 0;
                flag &= qmax(1, l, r) - pre[l - 1] <= 0;
            }
            return flag;
        };
        for (int l = 1; l <= n; l++) {
            int lb = l, rb = n, r = l - 1;
            while (lb <= rb) {
                int mid = (lb + rb) / 2;
                chk(l, mid) ? lb = (r = mid) + 1 : rb = mid - 1;
            }
            Q[l - 1].emplace_back(pre[l - 1], -1);
            Q[r].emplace_back(pre[l - 1], 1);
        }
        long long ans = 0;
        map<long long, int> cnt;
        for (int i = 0; i <= n; i++) {
            cnt[pre[i]]++;
            for (auto &p : Q[i]) ans += cnt[p.first] * p.second;
        }
        printf("%lld\n", ans);
    }
    return 0;
}