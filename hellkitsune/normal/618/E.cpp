#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
double x[1 << 20], y[1 << 20];
int ang[1 << 20] = {};
const int off = 1 << 19;
double c[360], s[360];
const double PI = atan2(0, -1);

void stMerge(int v, int a, int b) {
    int rot = ang[a];
    double nx, ny;
    ang[v] = ang[a] + ang[b];
    if (ang[v] >= 360) ang[v] -= 360;
    if (rot == 0) {
        nx = x[b];
        ny = y[b];
    } else {
        nx = c[rot] * x[b] - s[rot] * y[b];
        ny = s[rot] * x[b] + c[rot] * y[b];
    }
    x[v] = x[a] + nx;
    y[v] = y[a] + ny;
}

void stBuild(int v, int L, int R) {
    if (L != R) {
        int mid = (L + R) >> 1;
        stBuild(2 * v, L, mid);
        stBuild(2 * v + 1, mid + 1, R);
        stMerge(v, 2 * v, 2 * v + 1);
    }
}

void stUpdate(int v, int L, int R, int pos) {
    if (L == R) return;
    int mid = (L + R) >> 1;
    if (pos <= mid) stUpdate(2 * v, L, mid, pos);
    else stUpdate(2 * v + 1, mid + 1, R, pos);
    stMerge(v, 2 * v, 2 * v + 1);
}

int main() {
    REP(i, 360) {
        c[i] = cos(-2 * i * PI / 360);
        s[i] = sin(-2 * i * PI / 360);
    }
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) x[off + i] = 1;
    stBuild(1, 0, off - 1);
    REP(i, m) {
        int qx, qy, qz;
        scanf("%d%d%d", &qx, &qy, &qz);
        if (qx == 1) {
            x[off + qy] += qz;
        } else {
            --qy;
            ang[off + qy] += qz;
            if (ang[off + qy] >= 360) ang[off + qy] -= 360;
        }
        stUpdate(1, 0, off - 1, qy);
        printf("%.12f %.12f\n", x[1], y[1]);
    }
    return 0;
}