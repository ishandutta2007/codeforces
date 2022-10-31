#include<bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash
#define rank _rank

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 2e5 + 100;

struct point{
    ld x, y;
    point (ld x = 0, ld y = 0) : x(x), y(y) {}
};

point operator-(point a, point b) {
    return point(a.x - b.x, a.y - b.y);
}

double operator^(point a, point b) {
    return a.x * b.y - a.y * b.x;
}
double operator*(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

point rot90(point a) {
    return point(-a.y, a.x);
}

int n;
ld a[N];
vector<point> points;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif

    scanf("%d", &n);
    points.eb(0, 0);
    for (int i = 0, s = 0; i < n; i++) {
        int b;
        scanf("%d", &b);
        a[i] = b;
        points.eb(i + 1, a[i] + s);
        s += a[i];
    }
    vector<point> down, up;
    for (int i = 0; i <= n; i++) {
        while (down.size() > 1) {
            if (((down[(int) down.size() - 1] - down[(int) down.size() - 2]) ^ (points[i] - down[(int) down.size() - 2])) < 0) {
                down.pop_back();
            } else {
                break;
            }
        }
        down.pb(points[i]);
    }
    for (int i = 0; i <= n; i++) {
        while (up.size() > 1) {
            if (((up[(int) up.size() - 1] - up[(int) up.size() - 2]) ^ (points[i] - up[(int) up.size() - 2])) > 0) {
                up.pop_back();
            } else {
                break;
            }
        }
        up.pb(points[i]);
    }
//    for (auto i : down) {
//        cout << i.x << ' ' << i.y << endl;
//    }
//    cout << endl;
//    for (auto i : up) {
//        cout << i.x << ' ' << i.y << endl;
//    }
    ld ans = 1e18;
    for (int i = 0, j = (int) up.size() - 1; i + 1 < down.size(); i++) {
        point cur = rot90(down[i + 1] - down[i]);
        while (j > 0) {
            if (up[j] * cur < up[j - 1] * cur) {
                j--;
            } else {
                break;
            }
        }
        ans = min(ans, up[j].y - (down[i].y + (down[i + 1].y - down[i].y) / (down[i + 1].x - down[i].x) * (up[j].x - down[i].x)));
    }
    for (int i = 0, j = (int) down.size() - 1; i + 1 < up.size(); i++) {
        point cur = rot90(up[i + 1] - up[i]);
        while (j > 0) {
            if (down[j] * cur > down[j - 1] * cur) {
                j--;
            } else {
                break;
            }
        }
        ans = min(ans, abs(down[j].y - (up[i].y + (up[i + 1].y - up[i].y) / (up[i + 1].x - up[i].x) * (down[j].x - up[i].x))));
    }

    printf("%.18lf\n", (double) ans);

    return 0;
}