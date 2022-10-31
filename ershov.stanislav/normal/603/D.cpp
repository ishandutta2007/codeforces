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

const int INF = 1e9;
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
    point (ld x = 0, ld y = 0) : x(x), y(y) {}
    point operator-(const point & b) const {
        return point(x - b.x, y - b.y);
    }
    ld operator*(const point & b) const {
        return x * b.x + y * b.y;
    }
    point operator*(const ld & b) const {
        return point(x * b, y * b);
    }
    ld len() const {
        return sqrt(x * x + y * y);
    }
    point norm() const {
        ld l = len();
        point ans = point(x / l, y / l);
        if (ans.x < -EPS) {
            ans.x = -ans.x;
            ans.y = -ans.y;
        }
        if (abs(ans.x) < EPS && ans.y < -EPS) {
            ans.x = -ans.x;
            ans.y = -ans.y;
        }
        return ans;
    }
    void get() {
        x = getDouble();
        y = getDouble();
    }
};

bool operator<(const point & a, const point & b) {
    if (abs(a.x - b.x) > EPS) {
        return a.x < b.x;
    } else if (abs(a.y - b.y) > EPS) {
        return a.y < b.y;
    } else {
        return false;
    }
}
bool operator==(const point & a, const point & b) {
    return abs(a.x - b.x) <= EPS && abs(a.y - b.y) <= EPS;
}

const int maxn = 2200;

int n, c[maxn];
point ab[maxn];

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    vector<point> norms;
    for (int i = 0; i < n; i++) {
        ab[i].get();
        scanf("%d", &c[i]);
        norms.pb(ab[i] * (c[i] / (ab[i] * ab[i])));
        //cout << norms.back().x << ' ' << norms.back().y << endl;
    }
    ll ans = 0;
    for (int t = 0; t < n; t++) {
        vector<point> points;
        for (int i = 0; i < n; i++) {
            if (i == t) {
                continue;
            }
            if ((norms[i] - norms[t]).len() < EPS) {
                ans += n - 2;
            } else {
                points.pb((norms[i] - norms[t]).norm());
            }
        }
        sort(all(points));
        for (int i = 0; i < sz(points); ) {
            int i0 = i;
            while (i < sz(points) && points[i] == points[i0]) {
                i++;
            }
            ans += (ll) (i - i0) * (i - i0 - 1) / 2;
        }
    }
    assert(ans % 3 == 0);
    printf(LLD "\n", ans / 3);
    return 0;
}