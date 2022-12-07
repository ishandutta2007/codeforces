#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second

int n, m;
PII r[1005], b[1005];
double ang[1005];
int ord[1005];

const double PI = acosl(-1);
const double EPS = 1e-9;

bool cmp(const int &lhs, const int &rhs) {
    return ang[lhs] < ang[rhs];
}

inline PII operator-(const PII &a, const PII &b) {return mp(a.x - b.x, a.y - b.y);}
inline PII operator+(const PII &a, const PII &b) {return mp(a.x + b.x, a.y + b.y);}

bool sameLine(PII p, PII q) {
    if (p.x == 0) return q.x == 0;
    if (p.y == 0) return q.y == 0;
    return (LL)p.x * q.y == (LL)p.y * q.x;
}

typedef pair<double, double> P;

P nr[1005];
P nb[1005], h[2005];


double dist(double x, double y) {
    return sqrt(x * x + y * y);
}

bool cw(const P &a, const P &b, const P &c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) < 0;
}

int convexHull(int n) {
    if (n <= 1)
        return n;
    int k = 0;
    sort(nb, nb + n);
    for (int i = 0; i < n; h[k++] = nb[i++])
        for (; k >= 2 && !cw(h[k - 2], h[k - 1], nb[i]); --k)
            ;
    for (int i = n - 2, t = k; i >= 0; h[k++] = nb[i--])
        for (; k > t && !cw(h[k - 2], h[k - 1], nb[i]); --k)
            ;
    forn(i, k - 1) {
        nb[i] = h[i];
    }
    return k - 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    forn(i, n) scanf("%d%d", &r[i].x, &r[i].y);
    forn(i, m) scanf("%d%d", &b[i].x, &b[i].y);
    if (m <= 2) {
        cout << -1 << endl;
        return 0;
    }
    forn(i, n) {
        forn(j, m) {
            PII p = b[j] - r[i];
            ang[j] = atan2(p.y, p.x);
        }
        forn(j, m) {
            ord[j] = j;
        }
        sort(ord, ord + m, cmp);
        ord[m] = ord[0];
        ang[m] = ang[0] + 2 * PI;
        forn(j, m) {
            int pp = ord[j];
            int qq = ord[j + 1];
            PII p = b[pp];
            PII q = b[qq];
            if (ang[qq] - ang[pp] > PI + EPS) {
                cout << -1 << endl;
                return 0;
            }
            if (ang[qq] - ang[pp] > PI - EPS && sameLine(p - r[i], q - r[i])) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    double ans = 0;
    forn(z, m) {
        forn(i, n) {
            P p = r[i] - b[z];
            double len = dist(p.x, p.y);
            double mul = 1 / (len * len);
            p.x *= mul;
            p.y *= mul;
            nr[i] = p;
        }
        forn(i, m) {
            if (i == z) {
                continue;
            }
            P p = b[i] - b[z];
            double len = dist(p.x, p.y);
            double mul = 1 / (len * len);
            p.x *= mul;
            p.y *= mul;
            if (i < z) {
                nb[i] = p;
            } else {
                nb[i - 1] = p;
            }
        }
        nb[m - 1] = mp(0, 0);
        int sz = convexHull(m);
        nb[sz] = nb[0];
        forn(i, sz) {
            double a = nb[i].y - nb[i + 1].y;
            double b = nb[i + 1].x - nb[i].x;
            double c = -(a * nb[i].x + b * nb[i].y);
            bool ok = false;
            forn(j, n) {
                if (a * nr[j].x + b * nr[j].y + c > 0) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                ans = max(ans, abs(0.5 * sqrt(a * a + b * b) / max(1e-50, abs(c))));
            }
        }
    }
    forn(z, n) {
        forn(i, n) {
            if (i == z) {
                continue;
            }
            P p = r[i] - r[z];
            double len = dist(p.x, p.y);
            double mul = 1 / (len * len);
            p.x *= mul;
            p.y *= mul;
            if (i < z) {
                nr[i] = p;
            } else {
                nr[i - 1] = p;
            }
        }
        forn(i, m) {
            P p = b[i] - r[z];
            double len = dist(p.x, p.y);
            double mul = 1 / (len * len);
            p.x *= mul;
            p.y *= mul;
            nb[i] = p;
        }
        nb[m] = mp(0, 0);
        int sz = convexHull(m + 1);
        nb[sz] = nb[0];
        forn(i, sz) {
            double a = nb[i].y - nb[i + 1].y;
            double b = nb[i + 1].x - nb[i].x;
            double c = -(a * nb[i].x + b * nb[i].y);
            ans = max(ans, abs(0.5 * sqrt(a * a + b * b) / max(1e-50, abs(c))));
        }
    }
    if (ans > 1e20) {
        cout << -1 << endl;
        return 0;
    }
    printf("%.15f\n", ans);
    return 0;
}