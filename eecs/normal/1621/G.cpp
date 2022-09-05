#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 1000000007;
int T, n, a[maxn], f[maxn], g[maxn], id[maxn];
int ways[maxn], val[maxn], suf[maxn];
vector<int> pos[maxn];

void red(int &x) {
    x += x >> 31 & P;
}

struct BIT {
    int c[maxn];
    void init() { fill(c, c + n + 1, 0); }

    void add(int p, int v) {
        for (; p <= n; p += p & -p) red(c[p] += v - P);
    }
    void clear(int p) {
        for (; p <= n; p += p & -p) c[p] = 0;
    }
    int sum(int p) {
        int s = 0;
        for (; p; p -= p & -p) red(s += c[p] - P);
        return s;
    }
} c1, c2;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        vector<int> V(a + 1, a + n + 1);
        sort(V.begin(), V.end());
        V.resize(unique(V.begin(), V.end()) - V.begin());
        for (int i = 1; i <= n; i++) {
            a[i] = lower_bound(V.begin(), V.end(), a[i]) - V.begin() + 1;
        }
        c1.init(), c2.init();
        int ans = 0;
        suf[n + 1] = 0;
        for (int i = n; i; i--) {
            suf[i] = max(suf[i + 1], a[i]);
        }
        for (int i = 1; i <= n; i++) {
            c1.add(a[i], f[i] = (c1.sum(a[i] - 1) + 1) % P);
            g[i] = (f[i] + c2.sum(a[i] - 1)) % P;
            c2.add(a[i], g[i]), red(ans += g[i] - P);
        }
        c1.init();
        vector<int> cand;
        for (int i = 1; i <= n; i++) {
            pos[i].clear();
            if (a[i] > suf[i + 1]) cand.push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            int l = lower_bound(cand.begin(), cand.end(), i) - cand.begin();
            int r = cand.size() - 1, p = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (a[cand[mid]] > a[i]) l = (p = mid) + 1;
                else r = mid - 1;
            }
            if (~p) pos[cand[p]].push_back(i);
            else pos[i].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            for (int j : pos[i]) {
                int t = (c1.sum(a[j] - 1) + f[j]) % P;
                c1.add(a[j], t);
                if (i == j) red(ans -= t);
            }
            for (int j : pos[i]) c1.clear(a[j]);
        }
        printf("%d\n", ans);
    }
    return 0;
}