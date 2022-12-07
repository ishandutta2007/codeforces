#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
LL x[100000], y[100000], z[100000];
LL a[100000], b[100000], c[100000], d[100000];

LL solve() {
    REP(i, n) {
        a[i] = x[i] + y[i] + z[i];
        b[i] = x[i] - y[i] + z[i];
        c[i] = x[i] + y[i] - z[i];
        d[i] = x[i] - y[i] - z[i];
    }
    LL ax, ay, az;
    LL aa, bb, cc;
    aa = bb = cc = -1;
    LL lo = 0, hi = 3.01e18, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        LL abeg, bbeg, cbeg, dbeg, aed, bed, ced, ded;
        abeg = bbeg = cbeg = dbeg = -9.05e18;
        aed = bed = ced = ded = 9.05e18;
        for (int i = 0; i < n; ++i) {
            abeg = max(abeg, a[i] - mid);
            bbeg = max(bbeg, b[i] - mid);
            cbeg = max(cbeg, c[i] - mid);
            dbeg = max(dbeg, d[i] - mid);
            aed = min(aed, a[i] + mid);
            bed = min(bed, b[i] + mid);
            ced = min(ced, c[i] + mid);
            ded = min(ded, d[i] + mid);
        }
        dbeg = max(dbeg, bbeg + cbeg - aed);
        ded = min(ded, bed + ced - abeg);
        if (abeg > aed || bbeg > bed || cbeg > ced || dbeg > ded) {
            lo = mid + 1;
        } else {
            hi = mid;
            aa = aed;
            bb = bbeg;
            cc = cbeg;
            LL sum = bb + cc - aa;
            if (sum < dbeg) {
                LL ad = min(bed - bbeg, dbeg - sum);
                sum += ad;
                bb += ad;
                ad = min(ced - cbeg, dbeg - sum);
                sum += ad;
                cc += ad;
                ad = min(aed - abeg, dbeg - sum);
                sum += ad;
                aa -= ad;
            }
        }
    }
    double aaz = double(aa - cc) / 2;
    double aay = double(aa - bb) / 2;
    double aax = aa - aay - aaz;
    LL bbx = ax = aax;
    LL bby = ay = aay;
    LL bbz = az = aaz;
    LL best = 9.05e18;
    for (LL bx = bbx - 1; bx <= bbx + 1; ++bx) {
        for (LL by = bby - 1; by <= bby + 1; ++by) {
            for (LL bz = bbz - 1; bz <= bbz + 1; ++bz) {
                LL cur = 0;
                REP(i, n) cur = max(cur, abs(bx - x[i]) + abs(by - y[i]) + abs(bz - z[i]));
                if (cur < best) {
                    best = cur;
                    ax = bx;
                    ay = by;
                    az = bz;
                }
            }
        }
    }
    printf("%I64d %I64d %I64d\n", ax, ay, az);
}

int tt;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &tt);
    REP(test, tt) {
        scanf("%d", &n);
        REP(i, n) {
            scanf("%I64d%I64d%I64d", x + i, y + i, z + i);
        }
        solve();
    }
    return 0;
}