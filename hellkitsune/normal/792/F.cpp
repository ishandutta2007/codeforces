#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int test;

int q;
LL mana, m;

bool cw(PII a, PII b, PII c) {
    return LL(b.first - a.first) * (c.second - a.second) - LL(b.second - a.second) * (c.first - a.first) > 0;
}

set<PII> se;

void upd(set<PII>::iterator it) {
    while (it != se.begin()) {
        auto pre = it;
        --pre;
        if (pre->second >= it->second) {
            se.erase(pre);
        } else {
            break;
        }
    }
    while (true) {
        auto nx = it;
        ++nx;
        if (nx == se.end()) {
            break;
        }
        auto nx2 = nx;
        ++nx2;
        if (nx2 == se.end()) {
            break;
        }
        if (!cw(*it, *nx, *nx2)) {
            se.erase(nx);
        } else {
            break;
        }
    }
    while (true) {
        if (it == se.begin()) {
            break;
        }
        auto pre = it;
        --pre;
        if (pre == se.begin()) {
            break;
        }
        auto pre2 = pre;
        --pre2;
        if (!cw(*pre2, *pre, *it)) {
            se.erase(pre);
        } else {
            break;
        }
    }
}

void solve() {
    cin >> q >> mana;
    se.clear();
    se.insert(mp(0, 0));
    int lastYes = 0;
    for (int qnum = 1; qnum <= q; ++qnum) {
        int qt, a, b;
        scanf("%d%d%d", &qt, &a, &b);
        a = (a + lastYes) % 1000000 + 1;
        b = (b + lastYes) % 1000000 + 1;
        if (qt == 1) {
            auto it = se.lower_bound(mp(a, -1));
            if (it != se.end() && it->first == a) {
                if (it->second > b) {
                    se.erase(it);
                    upd(se.insert(mp(a, b)).first);
                }
                continue;
            }
            if (it == se.end()) {
                upd(se.insert(mp(a, b)).first);
                continue;
            }
            auto nx = it;
            if (nx != se.end() && nx->second <= b) {
                continue;
            }
            if (it == se.begin() || nx == se.end()) {
                upd(se.insert(mp(a, b)).first);
                continue;
            }
            --it;
            if (cw(*it, mp(a, b), *nx)) {
                upd(se.insert(mp(a, b)).first);
            }
        } else {
            auto it = se.lower_bound(mp((b + a - 1) / a, -1));
            if (it == se.end()) {
                printf("NO\n");
                continue;
            }
            if (it == se.begin() || b == (LL)it->first * a) {
                if ((LL)b * it->second <= mana * it->first) {
                    printf("YES\n");
                    lastYes = qnum;
                } else {
                    printf("NO\n");
                }
                continue;
            }
            PII hi = *it;
            --it;
            PII lo = *it;
            long double k = ((long double)b / a - lo.first) / (hi.first - (long double)b / a);
            long double manaReq = (lo.second + k * hi.second) / (k + 1) * a;
            if (manaReq < mana + (long double)1e-12) {
                printf("YES\n");
                lastYes = qnum;
            } else {
                printf("NO\n");
            }
        }
    }
}

int main() {
    solve();
    return 0;
}