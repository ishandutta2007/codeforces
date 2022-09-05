#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, K, q, global, global_cnt;
int a[maxn], b[maxn], c[maxn];

struct {
    int n, SZ, all, num;
    vector<int> a, xors, bl, br, bel;
    vector<vector<short>> cnt;

    void init(vector<int> _a) {
        a = _a, n = a.size() - 1, SZ = sqrt(n + 1);
        xors = bl = br = bel = vector<int>(n + 1);
        for (int i = 0; i <= n; i++) {
            br[bel[i] = i / SZ] = i;
            if (!(i % SZ)) bl[bel[i]] = i;
        }
        if (n > 3000) {
            cnt = vector<vector<short>>(bel[n] + 1, vector<short>(1 << 14));
            for (int i = 0, j = 0; i <= n; i++) {
                xors[bel[i]] ^= a[i], cnt[bel[i]][a[i] ^ j]++;
                if (i == br[bel[i]]) j = 0;
                else j ^= a[i];
            }
        }
    }

    void calc() {
        all = 0, num = n + 1;
        if (n > 3000) {
            for (int i = 0; i <= bel[n]; i++) num -= cnt[i][all], all ^= xors[i];
        } else {
            for (int i = 0; i <= n; i++) num -= (a[i] == all), all ^= a[i];
        }
        if (all) global_cnt++;
        global += num;
    }

    void upd(int p, int v) {
        if (all) global_cnt--;
        global -= num;
        if (n > 3000) {
            for (int i = bl[bel[p]], j = 0; i <= br[bel[p]]; i++) {
                cnt[bel[p]][a[i] ^ j]--, j ^= a[i];
            }
            xors[bel[p]] ^= a[p] ^ v;
        }
        a[p] = v;
        if (n > 3000) {
            for (int i = bl[bel[p]], j = 0; i <= br[bel[p]]; i++) {
                cnt[bel[p]][a[i] ^ j]++, j ^= a[i];
            }
        }
        calc();
    }
} foo[maxn];

int main() {
    scanf("%d %d %d", &n, &K, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]), c[i] = a[i] ^ b[i];
    }
    for (int i = 0; i < K; i++) {
        vector<int> a;
        for (int j = i; j <= n + 1; j += K) {
            a.push_back(!j ? 0 : (c[j] ^ c[j - 1]));
        }
        foo[i].init(a), foo[i].calc();
    }
    printf("%d\n", global_cnt ? -1 : global);
    while (q--) {
        char op[2]; int p, v;
        scanf("%s %d %d", op, &p, &v);
        if (op[0] == 'a') c[p] = (a[p] = v) ^ b[p];
        else c[p] = a[p] ^ (b[p] = v);
        foo[p % K].upd(p / K, c[p] ^ c[p - 1]);
        foo[(p + 1) % K].upd((p + 1) / K, c[p + 1] ^ c[p]);
        printf("%d\n", global_cnt ? -1 : global);
    }
    return 0;
}