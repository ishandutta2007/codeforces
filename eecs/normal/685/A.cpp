#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m, ans;
bool vis[7];

int main() {
    scanf("%d %d", &n, &m);
    long long cur = 7;
    int cnt1 = 1, cnt2 = 1;
    while (cur < n) cur *= 7, cnt1++;
    cur = 7;
    while (cur < m) cur *= 7, cnt2++;
    map<int, int> mp1, mp2;
    function<void(ll, int)> dfs1 = [&](ll cur, int num) {
        if (cur >= n || num > cnt1) return;
        if (num == cnt1) {
            int S = 0;
            for (int i = 0; i < 7; i++) {
                if (vis[i]) S |= 1 << i;
            }
            mp1[S]++; return;
        }
        for (int i = 0; i < 7; i++) if (!vis[i]) {
            vis[i] = 1;
            dfs1(cur * 7 + i, num + 1);
            vis[i] = 0;
        }
    };
    dfs1(0, 0);
    function<void(ll, int)> dfs2 = [&](ll cur, int num) {
        if (cur >= m || num > cnt2) return;
        if (num == cnt2) {
            int S = 0;
            for (int i = 0; i < 7; i++) {
                if (vis[i]) S |= 1 << i;
            }
            mp2[S]++; return;
        }
        for (int i = 0; i < 7; i++) if (!vis[i]) {
            vis[i] = 1;
            dfs2(cur * 7 + i, num + 1);
            vis[i] = 0;
        }
    };
    dfs2(0, 0);
    for (auto p : mp1) for (auto q : mp2) if (!(p.first & q.first)) {
        ans += p.second * q.second;
    }
    printf("%d\n", ans);
    return 0;
}