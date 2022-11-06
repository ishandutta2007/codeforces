#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int M = 998244353;

int qpw(int a, int b) {
    a %= M;
    if (b < 0) {
        (b %= M - 1) += M - 1;
    }
    int c = 1;
    for (; b; b >>= 1, a = 1ll * a * a % M) {
        if (b & 1) {
            c = 1ll * c * a % M;
        }
    }
    return c;
}

int mod(int val) {
    return (val < 0) ? (val + M) : ((val >= M) ? (val - M) : val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int d, n, m;
    cin >> d >> n >> m;
    vector<int> cnt(d);
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        ++cnt[l];
    }
    vector<int> p(m), inv(d);
    inv[1] = 1;
    for (int i = 2; i < d; i++) {
        inv[i] = (-1ll * M / i) * inv[M % i] % M;
    }
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    m = p.size();

    vector pre(m, vector(d, 1));
    vector ipr(m, vector(d, 1));
    for (int i = 0; i < m; i++) {
        auto &pr = pre[i], &ip = ipr[i];
        for (int j = 1; j < d; j++) {
            pr[j] = pr[j - 1], ip[j] = ip[j - 1];
            if (j != p[i]) {
                for (int k = 0; k < cnt[j]; k++) {
                    pr[j] = 1ll * pr[j] * abs(j - p[i]) % M;
                    ip[j] = 1ll * ip[j] * inv[abs(j - p[i])] % M;
                }
            }
        }
    }
    auto getmul = [&](int i, int l, int r) -> int {
        if (p[i] >= l && p[i] <= r && cnt[p[i]]) {
            return 0;
        }
        return 1ll * pre[i][r] * ipr[i][l - 1] % M;
    };

    vector<int> num(1 << m, 1);
    for (int i = 0; i < (1 << m); i++) {
        int lst = -1;
        for (int j = 0; j < m; j++) {
            if (!((i >> j) & 1)) {
                if (lst == -1) {
                    num[i] = 1ll * num[i] * getmul(j, 1, p[j]) % M;
                } else {
                    int mid = (p[lst] + p[j]) >> 1;
                    num[i] = 1ll * num[i] * getmul(lst, p[lst], mid) % M * getmul(j, mid + 1, p[j]) % M;
                }
                lst = j;
            }
        }
        if (lst == -1) {
            num[i] = qpw(d + 1, n);
        } else {
            num[i] = 1ll * num[i] * getmul(lst, p[lst], d - 1) % M;
        }
    }
    for (int l = 1; l < (1 << m); l <<= 1) {
        for (int st = 0; st < (1 << m); st += (l << 1)) {
            for (int i = st; i < st + l; i++) {
                num[i + l] = mod(num[i + l] - num[i]);
            }
        }
    }
    vector sum(m, vector(m, 0));
    int all = 0;
    for (int i = 0; i < (1 << m); i++) {
        int l = m, r = -1;
        for (int j = 0; j < m; j++) {
            if (!((i >> j) & 1)) {
                l = min(l, j), r = j;
            }
        }
        if (l <= r) {
            sum[l][r] = mod(sum[l][r] + num[i]);
        } else {
            all = mod(all + num[i]);
        }
    }
    {
        vector tmp(m, vector(m, 0));
        tmp.swap(sum);
        for (int l = 0; l < m; l++) {
            for (int r = l; r < m; r++) {
                sum[l][r] = all;
                for (int x = l; x <= r; x++) {
                    for (int y = x; y <= r; y++) {
                        sum[l][r] = mod(sum[l][r] + tmp[x][y]);
                    }
                }
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        vector<int> id(m);
        for (int j = 0; j < m; j++) {
            id[j] = j;
        }
        sort(id.begin(), id.end(), [&](int a, int b) {
            return abs(p[a] - x) < abs(p[b] - x);
        });
        int lstlen = 0, num = all, l = m, r = -1, ans = 0;
        for (int j = 0; j < m; j++) {
            int nowlen = abs(p[id[j]] - x);
            ans = (ans + 1ll * (nowlen - lstlen) * num) % M;
            l = min(l, id[j]), r = max(r, id[j]);
            while (j + 1 < m && abs(p[id[j + 1]] - x) == nowlen) {
                ++j, l = min(l, id[j]), r = max(r, id[j]);
            }
            num = sum[l][r], lstlen = nowlen;
        }
        ans = (ans + 1ll * (d + 1 - lstlen) * num) % M;
        printf("%d\n", mod(ans));
    }
    return 0;
}