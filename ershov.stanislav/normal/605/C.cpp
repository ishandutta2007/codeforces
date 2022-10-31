#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

double getDouble() {
    double tmp;
    scanf("%lf", &tmp);
    return tmp;
}

struct point {
    ld x, y;
    point (ld x = 0, ld y = 0) : x(x), y(y) { }
    void get() {
        x = getDouble();
        y = getDouble();
    }
    ld operator^(const point & b) const {
        return x * b.y - y * b.x;
    }
    point operator-(const point & b) const {
        return point(x - b.x, y - b.y);
    }
    ld slen() const {
        return x * x + y * y;
    }
};

bool operator<(const point & a, const point & b) {
    ld prod = a ^ b;
    if (abs(prod) > EPS) {
        return prod > 0;
    } else {
        return a.slen() < b.slen();
    }
}

bool operator==(const point & a, const point & b) {
    return abs(a.x - b.x) <= EPS && abs(a.y - b.y) <= EPS;
}

const int maxn = 1e5 + 100;

point ps[maxn];
int n, cnv;
point convex[maxn];
ld p, q;

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    p = getDouble();
    q = getDouble();
    ld ans = INF;
    for (int i = 0; i < n; i++) {
        ps[i].get();
        ans = min(ans, max(p / ps[i].x, q / ps[i].y));
    }
    ps[n] = point(0, 0);
    n++;
    sort(ps, ps + n);
    /*for (int i = 0; i < n; i++) {
        cout << ps[i].x << ' ' << ps[i].y << endl;
    }*/
    for (int i = 0; i < n; i++) {
        if (cnv && ps[i] == convex[cnv - 1]) {
            continue;
        }
        while (cnv >= 2 && ((ps[i] - convex[cnv - 1]) < (convex[cnv - 1] - convex[cnv - 2]))) {
            cnv--;
        }
        convex[cnv++] = ps[i];
    }
    /*cout << cnv << endl;
    for (int i = 0; i < cnv; i++) {
        cout << convex[i].x << ' ' << convex[i].y << endl;
    }*/
    int i = (int) (lower_bound(convex, convex + cnv, point(p, q)) - convex);
    if (0 < i && i < cnv) {
        point a = convex[i - 1];
        point b = convex[i];
        if (abs(a ^ point(p, q)) < EPS || abs(b ^ point(p, q)) < EPS) {
            
        } else {
            ld cur = (point(p, q) ^ (a - b)) / (b ^ (a - b));
            ans = min(cur, ans);
        }
    }
    printf("%.18f", max(0.0, double(ans)));
    return 0;
}