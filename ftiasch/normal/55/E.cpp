// Codeforces Beta Round #51
// Problem E -- Very simple problem
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 111111;
const double EPS = 1e-8;

struct Point {
    int x, y;

    Point (int a = 0, int b = 0): x(a), y(b) {}

    void read () {
        scanf("%d%d", &x, &y);
    }
};

Point operator - (const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

long long det (const Point &a, const Point &b) {
    return (long long)a.x * b.y - (long long)a.y * b.x;
}

long long dot (const Point &a, const Point &b) {
    return (long long)a.x * b.x + (long long)a.y * b.y;
}

double ang (const Point &a, const Point &b) {
    return atan2(det(a, b), dot(a, b));
}

int n;
Point p[N];

bool isInside (const Point &o) {
    double tmp = 0;
    for (int i = 0; i < n; ++ i) {
        tmp += ang(p[i] - o, p[(i + 1) % n] - o);
    }
    return abs(tmp) > EPS;
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        p[i].read();
    }
    int t;
    scanf("%d", &t);
    while (t --) {
        Point o;
        o.read();
        if (isInside(o)) {
            long long result = (long long)n * (n - 1) * (n - 2) / 6;
            int j = 1;
            for (int i = 0; i < n; ++ i) {
                while (det(p[j] - p[i], o - p[i]) < 0) {
                    j = (j + 1) % n;
                }
                //printf("%d--%d\n", i, j);
                int total = j - i;
                if (total < 0) {
                    total += n;
                }
                result -= (long long)(total - 1) * (total - 2) / 2;
            }
            cout << result << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}