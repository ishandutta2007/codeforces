#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int maxn = 100010, SZ = 500, B = 19260817;
int n, q, a[maxn], bel[maxn], bl[SZ], br[SZ];
int l1[SZ], v1[SZ][SZ], l2[SZ], v2[SZ][SZ], chk[maxn];
ull pw[maxn], pre[SZ][SZ], suf[SZ][SZ];
pair<int, int> st[maxn];

int main() {
    scanf("%d %*d", &n);
    for (int i = pw[0] = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pw[i] = pw[i - 1] * B;
        br[bel[i] = (i - 1) / SZ + 1] = i;
        if (!bl[bel[i]]) bl[bel[i]] = i;
    }
    scanf("%d", &q);
    auto rebuild = [&](int k) {
        int *p = v1[k], *q = v2[k], &tp1 = l1[k] = 0, &tp2 = l2[k] = 0;
        for (int i = bl[k]; i <= br[k]; i++) {
            if (a[i] > 0) q[++tp2] = a[i];
            else if (!tp2) p[++tp1] = -a[i];
            else if (q[tp2] ^ -a[i]) return 0;
            else tp2--;
        }
        for (int i = 1; i <= tp1; i++) {
            pre[k][i] = pre[k][i - 1] * B + p[i];
        }
        suf[k][tp2 + 1] = 0;
        for (int i = tp2; i; i--) {
            suf[k][i] = suf[k][i + 1] * B + q[i];
        }
        return 1;
    };
    auto query = [&](int l, int r) {
        if (!((r - l) & 1)) return 0;
        if (bel[l] == bel[r]) {
            stack<int> st;
            for (int i = l; i <= r; i++) {
                if (a[i] > 0) st.push(a[i]);
                else if (st.empty() || st.top() ^ -a[i]) return 0;
                else st.pop();
            }
            return int(st.empty());
        }
        int tp = 0;
        for (int i = l; i <= br[bel[l]]; i++) {
            if (a[i] > 0) st[++tp] = {0, i};
            else if (!tp || a[st[tp].second] ^ -a[i]) return 0;
            else tp--;
        }
        for (int i = bel[l] + 1; i < bel[r]; i++) {
            if (!chk[i]) return 0;
            for (int cur = 1; cur <= l1[i]; cur++) {
                if (!tp) return 0;
                if (!st[tp].first) {
                    if (a[st[tp--].second] ^ v1[i][cur]) return 0;
                } else {
                    int t = min(st[tp].second, l1[i] - cur + 1), j = st[tp].first;
                    if (pre[i][cur + t - 1] - pre[i][cur - 1] * pw[t] != suf[j][st[tp].second
                        - t + 1] - suf[j][st[tp].second + 1] * pw[t]) return 0;
                    st[tp].second -= t, cur += t - 1;
                    if (!st[tp].second) tp--;
                }
            }
            if (l2[i]) st[++tp] = {i, l2[i]};
        }
        for (int i = bl[bel[r]]; i <= r; i++) {
            if (a[i] > 0) { st[++tp] = {0, i}; continue;  }
            if (!tp) return 0;
            if (!st[tp].first) {
                if (a[st[tp--].second] ^ -a[i]) return 0;
            } else {
                if (v2[st[tp].first][st[tp].second] ^ -a[i]) return 0;
                if (!--st[tp].second) tp--;
            }
        }
        return int(!tp);
    };
    for (int i = 1; i <= bel[n]; i++) {
        chk[i] = rebuild(i);
    }
    for (int _ = 1, op, l, r; _ <= q; _++) {
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1) a[l] = r, chk[bel[l]] = rebuild(bel[l]);
        else puts(query(l, r) ? "Yes" : "No");
    }
    return 0;
}