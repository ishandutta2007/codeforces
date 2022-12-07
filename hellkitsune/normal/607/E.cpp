#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef long double Double;

int n, m;
Double p, q;
Double a[50000], b[50000];

bool isect(Double r, Double a, Double b, Double c, Double &ix1, Double &ix2, bool &up1, bool &up2) {
    if (c * c > r * r * (a * a + b * b)) return false;
    Double dist = r * r - c * c / (a * a + b * b);
    Double mul = sqrt(dist / (a * a + b * b));
    Double x = -a * c / (a * a + b * b);
    Double y = -b * c / (a * a + b * b);
    ix1 = x + b * mul;
    ix2 = x - b * mul;
    up1 = y - a * mul > 0;
    up2 = y + a * mul > 0;
    return true;
}

inline bool isect(Double x, Double y, Double r, Double a, Double b, Double c, Double &ix1, Double &ix2, bool &up1, bool &up2) {
    return isect(r, a, b, a * x + b * y + c, ix1, ix2, up1, up2);
}

struct Ev {
    Double x;
    int ind;
    bool up;
    Ev(Double x, int ind, bool up) : x(x), ind(ind), up(up) {}
};

inline bool cmp(const Ev &lhs, const Ev &rhs) {
    return lhs.x < rhs.x;
}

vector<Ev> ev;
int pos[50000], fen[100000], rev[100000];
int cnt;

void fenInc(int pos) {
    for (; pos < 100000; pos |= pos + 1) {
        ++fen[pos];
    }
}

void fenDec(int pos) {
    for (; pos < 100000; pos |= pos + 1) {
        --fen[pos];
    }
}

int fenGet(int pos) {
    int res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        res += fen[pos];
    }
    return res;
}

int solve(Double ra) {
    Double ix1, ix2;
    bool up1, up2;
    ev.clear();
    REP(i, n) if (isect(p, q, ra, a[i], -1, b[i], ix1, ix2, up1, up2)) {
        ev.pb(Ev(ix1, i, up1));
        ev.pb(Ev(ix2, i, up2));
    }
    sort(ev.begin(), ev.end(), cmp);
    int cnt = 0;
    memset(fen, 0, sizeof fen);
    memset(pos, -1, sizeof pos);
    int res = 0;
    int le = 49999, ri = 50000;
    for (auto e : ev) if (pos[e.ind] == -1) {
        if (e.up) pos[e.ind] = le--;
        else pos[e.ind] = ri++;
        fenInc(pos[e.ind]);
        ++cnt;
    } else {
        if (e.up) res += fenGet(pos[e.ind] - 1);
        else res += cnt - fenGet(pos[e.ind]);
        fenDec(pos[e.ind]);
        --cnt;
    }
    return res;
}

Double v[30000000];
int vc = 0;

Double gra;

void addPoint(int i, int j) {
    if (vc >= m) return;
    Double x = (b[i] - b[j]) / (a[j] - a[i]);
    Double y = a[i] * x + b[i];
    v[vc++] = sqrt((x - p) * (x - p) + (y - q) * (y - q));
}

set<PII> se;

void solve2(Double ra) {
    gra = ra;
    Double ix1, ix2;
    bool up1, up2;
    ev.clear();
    REP(i, n) if (isect(p, q, ra, a[i], -1, b[i], ix1, ix2, up1, up2)) {
        ev.pb(Ev(ix1, i, up1));
        ev.pb(Ev(ix2, i, up2));
    }
    memset(pos, -1, sizeof pos);
    sort(ev.begin(), ev.end(), cmp);
    int le = 49999, ri = 50000;
    for (auto e : ev) if (pos[e.ind] == -1) {
        if (e.up) pos[e.ind] = le--;
        else pos[e.ind] = ri++;
        se.insert(mp(pos[e.ind], e.ind));
    } else {
        auto it = se.lower_bound(mp(pos[e.ind], e.ind));
        if (e.up) {
            auto it2 = it;
            while (true) {
                if (it2 == se.begin()) break;
                --it2;
                addPoint(e.ind, it2->second);
            }
        } else {
            auto it2 = it;
            while (true) {
                if (++it2 == se.end()) break;
                addPoint(e.ind, it2->second);
            }
        }
        se.erase(it);
    }
    Double ans = 0;
    REP(i, vc) ans += v[i];
    ans += (m - vc) * ra;
    printf("%.12f\n", (double)ans);
}

int main() {
    int tmp, tmp2;
    scanf("%d%d%d%d", &n, &tmp, &tmp2, &m);
    p = 0.001 * tmp, q = 0.001 * tmp2;
    REP(i, n) {
        scanf("%d%d", &tmp, &tmp2);
        a[i] = 0.001 * tmp;
        b[i] = 0.001 * tmp2;
    }
    Double lo = 0, hi = 1e10, mid;
    REP(times, 100) {
        mid = 0.5 * (lo + hi);
        if (solve(mid) >= m) hi = mid;
        else lo = mid;
    }
    solve2(lo);
    return 0;
}