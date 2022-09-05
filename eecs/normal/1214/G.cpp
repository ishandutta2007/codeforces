#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, m, q;
bitset<maxn> b[maxn], pw[maxn], tmp;
set<pair<int, int>> S, ans;

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= m; i++) {
        pw[i] = pw[i - 1] << 1, pw[i][1] = 1;
    }
    for (int i = 1; i <= n; i++) {
        S.emplace(0, i);
    }
    auto chk = [&](int i, int j, bool del = 0) {
        if (!~i || !~j || (b[i] & b[j]) == b[i]) return;
        !del ? (void)ans.emplace(i, j) : (void)ans.erase({i, j});
    };
    auto ins = [&](pair<int, int> p) {
        auto it = S.lower_bound(p);
        int pre = it == S.begin() ? -1 : prev(it)->second;
        int nxt = it == S.end() ? -1 : it->second;
        chk(pre, p.second), chk(p.second, nxt);
        chk(pre, nxt, 1), S.insert(p);
    };
    auto del = [&](pair<int, int> p) {
        auto it = S.lower_bound(p);
        int pre = it == S.begin() ? -1 : prev(it)->second;
        int nxt = next(it) == S.end() ? -1 : next(it)->second;
        chk(pre, p.second, 1), chk(p.second, nxt, 1);
        chk(pre, nxt), S.erase(p);
    };
    while (q--) {
        int i, l, r; scanf("%d %d %d", &i, &l, &r);
        del(make_pair(b[i].count(), i));
        b[i] ^= pw[r - l + 1] << (l - 1);
        ins(make_pair(b[i].count(), i));
        if (ans.empty()) { puts("-1"); continue; }
        int x1 = ans.begin()->first, x2 = ans.begin()->second;
        tmp = b[x1] ^ b[x2];
        int y1 = (tmp & b[x1])._Find_first(), y2 = (tmp & b[x2])._Find_first();
        printf("%d %d %d %d\n", min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2));
    }
    return 0;
}