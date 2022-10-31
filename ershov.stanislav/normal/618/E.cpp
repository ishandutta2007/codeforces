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

const int maxn = (1 << 20) + 100;
const ld PI = acos(-1.0);

struct point {
    ld x, y;
    point (ld x = 0, ld y = 0) : x(x), y(y) { }
    point operator+(const point & b) const {
        return point(x + b.x, y + b.y);
    }
    point rotate(ld a) const {
        ld cs = cos(a), sn = sin(a);
        return point(x * cs - y * sn, y * cs + x * sn);
    }
    ld len() const {
        return sqrt(x * x + y * y);
    }
    point norm() const {
        ld l = len();
        return point(x / l, y / l);
    }
    point operator*(const ld & b) const {
        return point(x * b, y * b);
    }
    void print() {
        printf("%.18f %.18f\n", (double) x, (double) y);
    }
};

point tree[maxn];
int torot[maxn];
int n;

void build(int v, int vl, int vr) {
    if (vl == vr - 1) {
        tree[v] = point(1, 0);
    } else {
        int mid = (vl + vr) / 2;
        build(v * 2, vl, mid);
        build(v * 2 + 1, mid, vr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

void push(int v) {
    if (torot[v] == 0) {
        return;
    }
    ld ang = PI / 180.0 * torot[v];
    for (int i = 0; i < 2; i++) {
        torot[v * 2 + i] += torot[v];
        tree[v * 2 + i] = tree[v * 2 + i].rotate(ang);
    }
    torot[v] = 0;
}

point get(int i) {
    int v = 1, vl = 0, vr = n;
    while (vl != vr - 1) {
        push(v);
        int mid = (vl + vr) / 2;
        if (i < mid) {
            vr = mid;
            v = v * 2;
        } else {
            vl = mid;
            v = v * 2 + 1;
        }
    }
    return tree[v];
}

void settree(int v, int vl, int vr, int i, point a) {
    if (vl == vr - 1) {
        torot[v] = 0;
        tree[v] = a;
    } else {
        push(v);
        int mid = (vl + vr) / 2;
        if (i < mid) {
            settree(v * 2, vl, mid, i, a);
        } else {
            settree(v * 2 + 1, mid, vr, i, a);
        }
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

void rottree(int v, int vl, int vr, int l, int r, int rot) {
    if (vr <= l || vl >= r) {
        return;
    }
    if (vl >= l && vr <= r) {
        tree[v] = tree[v].rotate(PI / 180.0 * rot);
        torot[v] += rot;
    } else {
        push(v);
        int mid = (vl + vr) / 2;
        rottree(v * 2, vl, mid, l, r, rot);
        rottree(v * 2 + 1, mid, vr, l, r, rot);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    int m;
    scanf("%d%d", &n, &m);
    build(1, 0, n);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x == 2) {
            rottree(1, 0, n, y - 1, n, -z);
        } else {
            point cur = get(y - 1);
            ld curlen = cur.len();
            settree(1, 0, n, y - 1, cur.norm() * (curlen + z));
        }
        tree[1].print();
    }
    return 0;
}