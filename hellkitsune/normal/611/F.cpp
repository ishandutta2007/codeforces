#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 1e9 + 7;
int n, h, w;
int u = 0, d = 0, l = 0, r = 0, hh = 0, ww = 0;
vector<int> vu, vd, vl, vr;
vector<pair<LL, int> > e;
char s[500005];

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &h, &w);
    scanf("%s", s);
    int ans = (LL)h * w % MOD;
    REP(i, n) {
        if (s[i] == 'U') {
            --hh;
            if (-hh > u) {
                u = -hh;
                vu.pb(i);
            }
        } else if (s[i] == 'D') {
            ++hh;
            if (hh > d) {
                d = hh;
                vd.pb(i);
            }
        } else if (s[i] == 'L') {
            --ww;
            if (-ww > l) {
                l = -ww;
                vl.pb(i);
            }
        } else {
            ++ww;
            if (ww > r) {
                r = ww;
                vr.pb(i);
            }
        }
        ans = (ans + (LL)max(0, h - u - d) * max(0, w - l - r)) % MOD;
    }
    h -= u + d;
    w -= l + r;
    if (h > 0 && w > 0) {
        if (hh == 0 && ww == 0) {
            printf("-1\n");
            return 0;
        }
        if (hh > 0) {
            for (int i = (int)vd.size() - hh; i < (int)vd.size(); ++i) {
                e.pb(mp(vd[i], 0));
            }
        }
        if (hh < 0) {
            for (int i = (int)vu.size() + hh; i < (int)vu.size(); ++i) {
                e.pb(mp(vu[i], 0));
            }
        }
        if (ww > 0) {
            for (int i = (int)vr.size() - ww; i < (int)vr.size(); ++i) {
                e.pb(mp(vr[i], 1));
            }
        }
        if (ww < 0) {
            for (int i = (int)vl.size() + ww; i < (int)vl.size(); ++i) {
                e.pb(mp(vl[i], 1));
            }
        }
        sort(e.begin(), e.end());
        int sz = (int)e.size();
        while ((int)e.size() < w + h + 3) {
            int ind = (int)e.size() - sz;
            e.pb(mp(e[ind].first + n, e[ind].second));
        }
        int pre = 0;
        for (PII x : e) {
            ans = (ans + (LL)w * h % MOD * (x.first - pre)) % MOD;
            if (x.second == 0) --h;
            else --w;
            if (h <= 0 || w <= 0) break;
            pre = x.first;
        }
    }
    printf("%d\n", ans);
    return 0;
}