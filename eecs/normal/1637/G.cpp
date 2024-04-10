#include <bits/stdc++.h>
using namespace std;

const int maxn = 70000;
int T, n, m, cnt[maxn], need[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n == 2) { puts("-1"); continue; }
        for (m = 1; m < n; m *= 2);
        fill(cnt + 1, cnt + n + 1, 1);
        fill(cnt + n + 1, cnt + m + 1, 0);
        priority_queue<int> Q;
        for (int i = 1; i <= n; i++) Q.push(i);
        vector<array<int, 2>> ans;
        auto rec = [&](auto &&self, int x) -> void {
            Q.push(x), cnt[x]++;
            for (int i = m; i && i >= x; i /= 2) {
                if (need[i - x]) need[i - x]--, self(self, i - x);
            }
        };
        while (!Q.empty()) {
            int x = Q.top(); Q.pop();
            if (!cnt[x] || x == m) continue;
            cnt[x]--;
            if (!x) { cnt[m]++, ans.push_back({0, m}); continue; }
            bool flag = 0;
            for (int i = m; i >= x; i /= 2) {
                int j = i - x;
                if (!cnt[j]) continue;
                cnt[j]--, ans.push_back({j, x});
                rec(rec, i), rec(rec, abs(j - x));
                flag = 1; break;
            }
            if (!flag) need[x]++;
        }
        printf("%d\n", ans.size());
        for (auto &p : ans) {
            printf("%d %d\n", p[0], p[1]);
        }
    }
    return 0;
}