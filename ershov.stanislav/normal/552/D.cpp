#include <bits/stdc++.h>

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

const int N = 2200;

struct point {
    int x, y;
    point (int x = 0, int y = 0) : x(x), y(y) {}

    point operator-(point b) {
        return point(x - b.x, y - b.y);
    }
    int operator^(point b) {
        return x * b.y - y * b.x;
    }
    void get() {
        scanf("%d%d", &x, &y);
    }
};
bool operator<(point a, point b) {
    return (a ^ b) > 0;
}

vector<point> all;
int n;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d", &n);

    all.resize(n);
    for (int i = 0; i < n; i++) {
        all[i].get();
    }

    ll ans = n * 1ll * (n - 1) * 1ll * (n - 2) / 2;

    for (int i = 0; i < n; i++) {
        vector<point> points;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                point p = all[j] - all[i];
                if (p.x < 0 || (p.x == 0 && p.y < 0)) {
                    p.x = -p.x;
                    p.y = -p.y;
                }
                points.pb(p);
            }
        }
        sort(all(points));
        for (int i = 0, j = 0; i < (int) points.size(); ) {
            while (j < (int) points.size() && (points[i] ^ points[j]) == 0) {
                j++;
            }
            ans -= (j - i) * (j - i - 1) / 2;
            i = j;
        }
    }

    cout << ans / 3 << endl;

    return 0;
}