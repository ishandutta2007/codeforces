#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MX = int(1e7);

int n, m;
int len[1000005];
vector<int> v[1000005];
vector<LL> sum[1000005];

LL solve(int ind, int h) {
    if (h <= 0) return 0;
    int cnt = lower_bound(v[ind].begin(), v[ind].end(), h) - v[ind].begin();
    if (cnt == 0) return 0;
    return (LL)cnt * h - sum[ind][cnt - 1];
}

int main() {
    if (0) {
        mt19937 mt(123);
        n = 1000000;
        m = 100000;
        forn(i, n) len[i] = mt() % 10 + 1;
    } else {
        scanf("%d%d", &n, &m);
        for (int i = 2; i <= n; ++i) {
            scanf("%d", len + i);
        }
    }
    for (int i = n; i >= 1; --i) {
        int lsz = 0, rsz = 0, ldist = MX, rdist = MX;
        int le = 2 * i;
        int ri = 2 * i + 1;
        if (le <= n) lsz = v[le].size(), ldist = len[le];
        if (ri <= n) rsz = v[ri].size(), rdist = len[ri];
        int sz = 1 + lsz + rsz;
        v[i].reserve(sz);
        v[i].resize(sz);
        v[i][0] = 0;
        int lind = 0, rind = 0;
        for (int ind = 1; ind < sz; ++ind) {
            if (lind != lsz && (rind == rsz || v[le][lind] + ldist < v[ri][rind] + rdist)) {
                v[i][ind] = v[le][lind] + ldist;
                ++lind;
            } else {
                v[i][ind] = v[ri][rind] + rdist;
                ++rind;
            }
        }
        while (v[i].back() > MX) {
            v[i].pop_back();
        }
        sum[i].reserve(v[i].size());
        sum[i].resize(v[i].size());
        sum[i][0] = 0;
        for (int j = 1; j < (int)v[i].size(); ++j) {
            sum[i][j] = sum[i][j - 1] + v[i][j];
        }
    }
    forn(_, m) {
        int from, h;
        scanf("%d%d", &from, &h);
        LL res = solve(from, h);
        while (from > 1) {
            h -= len[from];
            if (h <= 0) {
                break;
            }
            int par = from / 2;
            res += h;
            for (int i = 2 * par; i <= min(n, 2 * par + 1); ++i) {
                if (i != from) {
                    res += solve(i, h - len[i]);
                }
            }
            from = par;
        }
        printf("%I64d\n", res);
    }
    return 0;
}