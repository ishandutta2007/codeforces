#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, m, q, mx, pre[maxn][maxn];
int qx[maxn], qy[maxn], ans[maxn], L[maxn], R[maxn];
char s[maxn][maxn];

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &qx[i], &qy[i]), s[qx[i]][qy[i]] = 'X';
    }
    auto calc = [&](int y) {
        for (int i = 1; i <= n; i++) {
            L[i] = y + 1, R[i] = y - 1;
            int l = 1, r = y;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (pre[i][y] == pre[i][mid - 1]) r = (L[i] = mid) - 1;
                else l = mid + 1;
            }
            l = y, r = m;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (pre[i][mid] == pre[i][y - 1]) l = (R[i] = mid) + 1;
                else r = mid - 1;
            }
        }
        auto chk = [&](int k) {
            deque<int> ql, qr;
            for (int i = 1; i <= n; i++) {
                while (!ql.empty() && L[ql.back()] < L[i]) ql.pop_back();
                ql.push_back(i);
                while (!qr.empty() && R[qr.back()] > R[i]) qr.pop_back();
                qr.push_back(i);
                if (i >= k) {
                    while (ql.front() <= i - k) ql.pop_front();
                    while (qr.front() <= i - k) qr.pop_front();
                    if (R[qr.front()] - L[ql.front()] + 1 >= k) return 1;
                }
            }
            return 0;
        };
        int l = 1, r = min(n, m);
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (chk(mid)) mx = max(mx, mid), l = mid + 1;
            else r = mid - 1;
        }
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pre[i][j] = pre[i][j - 1] + (s[i][j] == 'X');
        }
    }
    for (int i = 1; i <= m; i++) {
        calc(i);
    }
    for (int i = q; i; i--) {
        ans[i] = mx, s[qx[i]][qy[i]] = '.';
        for (int j = 1; j <= m; j++) {
            pre[qx[i]][j] = pre[qx[i]][j - 1] + (s[qx[i]][j] == 'X');
        }
        calc(qy[i]);
    }
    for (int i = 1; i <= q; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}