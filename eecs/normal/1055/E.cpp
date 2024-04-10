#include <bits/stdc++.h>
using namespace std;

const int maxn = 1510;
int n, s, m, K, a[maxn], pre[maxn], f[maxn][maxn];
pair<int, int> p[maxn];
bool mark[maxn];

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &K);
    vector<int> V;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), V.push_back(a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) if (i ^ j) {
            if (p[i].first <= p[j].first && p[j].second <= p[i].second) {
                if (p[i] == p[j] && i < j) continue;
                mark[j] = 1;
            }
        }
    }
    int tot = 0;
    for (int i = 1; i <= m; i++) {
        if (!mark[i]) p[++tot] = p[i];
    }
    s = min(s, m = tot);
    sort(p + 1, p + m + 1);
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    auto chk = [&](int x) {
        memset(f, -0x3f, sizeof(f)), f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + (a[i] <= x);
        }
        int ans = 0;
        for (int i = 1; i <= s; i++) {
            int cur = 0, mx = f[i - 1][cur];
            deque<int> Q;
            Q.push_back(0);
            for (int j = 1; j <= m; j++) {
                while (p[cur + 1].second < p[j].first) mx = max(mx, f[i - 1][++cur]);
                f[i][j] = mx + pre[p[j].second] - pre[p[j].first - 1];
                while (!Q.empty() && Q.front() <= cur) Q.pop_front();
                if (!Q.empty()) {
                    int k = Q.front();
                    f[i][j] = max(f[i][j], f[i - 1][k] + pre[p[j].second] - pre[p[k].second]);
                }
                while (!Q.empty() && f[i - 1][Q.back()] - pre[p[Q.back()].second] < f[i - 1][j] - pre[p[j].second]) Q.pop_back();
                Q.push_back(j);
                ans = max(ans, f[i][j]);
            }
        }
        return ans;
    };
    int l = 0, r = V.size() - 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk(V[mid]) >= K ? r = (ans = mid) - 1 : l = mid + 1;
    }
    printf("%d\n", !~ans ? -1 : V[ans]);
    return 0;
}