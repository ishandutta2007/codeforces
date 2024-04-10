#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int t, n;
int a[100010];
int ans;
inline void Add(int &x, int y) {
    if ((x += y) >= mod) x -= mod;
}
inline void rmain() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    ans = 0;
    vector < pair < int, int > > tmp, cur;
    for (int i = n; i > 0; i--) {
        tmp = cur;
        cur.clear();
        for (auto [j, c] : tmp) {
            int cnt = (a[i] + j - 1) / j;
            ans = (ans + 1ll * (cnt - 1) * c % mod * i) % mod;
            j = a[i] / cnt;
            cur.push_back({j, c});
        }
        cur.push_back({a[i], 1});
        for (int j = cur.size() - 1; j > 0; j--) if (cur[j] < cur[j - 1]) swap(cur[j], cur[j - 1]);
        tmp = cur;
        cur.clear();
        for (int l = 0, r; l < tmp.size(); l = r + 1) {
            int cnt = tmp[l].second;
            for (r = l; r < tmp.size() - 1 && tmp[r + 1].first == tmp[r].first; ) Add(cnt, tmp[++r].second);
            cur.push_back({tmp[l].first, cnt});
        }
    }
    printf("%d\n", ans);
}
int main() {
    scanf("%d", &t);
    while (t--) rmain();
}