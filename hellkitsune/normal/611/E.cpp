#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int aa, bb, cc;
int p[200000];
int ff[7] = {};

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%d%d%d", &aa, &bb, &cc);
    REP(i, n) scanf("%d", p + i);
    REP(i, n) if (p[i] > aa + bb + cc) {
        printf("-1\n");
        return 0;
    }
    if (aa > bb) swap(aa, bb);
    if (aa > cc) swap(aa, cc);
    if (bb > cc) swap(bb, cc);
    if (aa + bb < cc) {
        REP(i, n) if (p[i] <= aa) ++ff[0];
        else if (p[i] <= bb) ++ff[1];
        else if (p[i] <= aa + bb) ++ff[2];
        else if (p[i] <= cc) ++ff[3];
        else if (p[i] <= aa + cc) ++ff[4];
        else if (p[i] <= bb + cc) ++ff[5];
        else ++ff[6];

        int lo = ff[3] + ff[4] + ff[5] + ff[6], hi = n, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            int f[7];
            REP(i, 7) f[i] = ff[i];
            int tot = mid;
            tot -= f[6] + f[5] + f[4];
            f[0] = max(0, f[0] - f[5]);
            int sub = min(f[1], f[4]);
            f[1] -= sub, f[4] -= sub;
            sub = min(f[0], f[4]);
            f[0] -= sub;
            int c = tot - f[3];
            for (int i = 2; i >= 0; --i) {
                sub = min(f[i], c);
                f[i] -= sub, c -= sub;
            }
            int a = tot, b = tot;
            a -= f[2], b -= f[2];
            b -= f[1];
            if (a < 0 || b < 0 || a + b < f[0]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        printf("%d\n", lo);
    } else {
        REP(i, n) if (p[i] <= aa) ++ff[0];
        else if (p[i] <= bb) ++ff[1];
        else if (p[i] <= cc) ++ff[2];
        else if (p[i] <= aa + bb) ++ff[3];
        else if (p[i] <= aa + cc) ++ff[4];
        else if (p[i] <= bb + cc) ++ff[5];
        else ++ff[6];

        int lo = ff[3] + ff[4] + ff[5] + ff[6], hi = n, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            int f[7];
            REP(i, 7) f[i] = ff[i];
            int tot = mid;
            tot -= f[6] + f[5] + f[4] + f[3];
            f[0] = max(0, f[0] - f[5]);
            int sub = min(f[1], f[4]);
            f[1] -= sub, f[4] -= sub;
            sub = min(f[0], f[4]);
            f[0] -= sub;
            for (int i = 2; i >= 0; --i) {
                sub = min(f[i], f[3]);
                f[i] -= sub, f[3] -= sub;
            }
            int a = tot, b = tot, c = tot;
            for (int i = 2; i >= 0; --i) {
                sub = min(f[i], c);
                f[i] -= sub, c -= sub;
            }
            a -= f[2], b -= f[2];
            b -= f[1];
            if (a < 0 || b < 0 || a + b < f[0]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        printf("%d\n", lo);
    }
    return 0;
}