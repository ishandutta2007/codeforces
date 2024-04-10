#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

struct P {
    double first, second;
    bool sp;
    P(double first, double second, bool sp) : first(first), second(second), sp(sp) {}
};

int n, m;
int x[4000], y[4000];
int sx, sy, tx, ty;
LL a, b, c;
vector<PDD> p;
vector<bool> sp;
vector<P> pp;
const double EPS = 1e-9;

inline bool cmpX(const P &lhs, const P &rhs) {
    return lhs.first < rhs.first;
}

inline bool cmpY(const P &lhs, const P &rhs) {
    return lhs.second < rhs.second;
}

int sgn(LL x, LL y, LL xx, LL yy) {
    LL val = x * yy - xx * y;
    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
}

void readNumber(int &x) {
    double d;
    scanf("%lf", &d);
    x = abs(d) * 100 + 0.5;
    if (d < 0) x *= -1;
}

bool check(LL x, LL y, LL xx, LL yy, LL xxx, LL yyy) {
    int sg = sgn(x, y, xxx, yyy);
    return !sg || sgn(x, y, xx, yy) == sg && sgn(xx, yy, xxx, yyy) == sg;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    REP(i, n) readNumber(x[i]), readNumber(y[i]);
    REP(i, 3 * n) x[n + i] = x[i], y[n + i] = y[i];
    REP(query, m) {
        readNumber(sx), readNumber(sy);
        readNumber(tx), readNumber(ty);
        a = sy - ty;
        b = tx - sx;
        c = a * sx + b * sy;
        p.clear();
        sp.clear();
        REP(i, n) if (a * x[i] + b * y[i] == c && a * x[i + 1] + b * y[i + 1] == c) {
            p.pb(mp(x[i], y[i]));
            p.pb(mp(x[i + 1], y[i + 1]));
            sp.pb(true), sp.pb(true);
        } else if (a * x[i] + b * y[i] != c && a * x[i + 1] + b * y[i + 1] != c) {
            LL aa = y[i + 1] - y[i];
            LL bb = x[i] - x[i + 1];
            LL cc = aa * x[i] + bb * y[i];
            LL det = a * bb - aa * b;
            if (det == 0) continue;
            double ix = ((double)c * bb - (double)cc * b) / det;
            double iy = ((double)a * cc - (double)aa * c) / det;
            int minX = min(x[i], x[i + 1]);
            int maxX = max(x[i], x[i + 1]);
            int minY = min(y[i], y[i + 1]);
            int maxY = max(y[i], y[i + 1]);
            if (ix > minX - EPS && ix < maxX + EPS && iy > minY - EPS && iy < maxY + EPS) {
                p.pb(mp(ix, iy));
                sp.pb(false);
            }
        }
        for (int i = 1; i <= n; ++i) if (a * x[i] + b * y[i] == c &&
            a * x[i - 1] + b * y[i - 1] != c && a * x[i + 1] + b * y[i + 1] != c) {
            if (check(x[i - 1] - x[i], y[i - 1] - y[i], -b, a, x[i + 1] - x[i], y[i + 1] - y[i]) ||
                check(x[i - 1] - x[i], y[i - 1] - y[i], b, -a, x[i + 1] - x[i], y[i + 1] - y[i])) {
                p.pb(mp(x[i], y[i]));
                sp.pb(false);
            }
        }
        int ed = -1;
        for (int beg = n; beg < 2 * n; ) if (a * x[beg] + b * y[beg] == c) {
            int end = beg + 1;
            while (a * x[beg - 1] + b * y[beg - 1] == c) --beg;
            while (a * x[end] + b * y[end] == c) ++end;
            --end;
            if (ed != -1 && end == ed + n) break;
            if (sgn(x[beg] - x[beg - 1], y[beg] - y[beg - 1], x[beg + 1] - x[beg], y[beg + 1] - y[beg]) *
                sgn(x[end] - x[end - 1], y[end] - y[end - 1], x[end + 1] - x[end], y[end + 1] - y[end]) < 0) {
                p.pb(mp(x[end], y[end]));
                sp.pb(false);
            }
            if (ed == -1) ed = end;
            beg = end + 1;
        } else {
            ++beg;
        }
        pp.clear();
        REP(i, p.size()) pp.pb(P(p[i].first, p[i].second, sp[i]));
        if (b == 0) sort(pp.begin(), pp.end(), cmpY);
        else sort(pp.begin(), pp.end(), cmpX);
        REP(i, p.size()) p[i].first = pp[i].first, p[i].second = pp[i].second, sp[i] = pp[i].sp;
        double ans = 0;
        bool curSp = false;
        PDD spPoint;
        REP(i, p.size()) {
            if (!curSp && (i & 1)) {
                ans += sqrt((p[i].first - p[i - 1].first) * (p[i].first - p[i - 1].first) +
                    (p[i].second - p[i - 1].second) * (p[i].second - p[i - 1].second));
            }
            if (sp[i]) {
                if (curSp) {
                    ans += sqrt((spPoint.first - p[i].first) * (spPoint.first - p[i].first) +
                        (spPoint.second - p[i].second) * (spPoint.second - p[i].second));
                } else {
                    spPoint = p[i];
                }
                curSp = !curSp;
            }
        }
        printf("%.18f\n", ans * 0.01);
    }
    return 0;
}