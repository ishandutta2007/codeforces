#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <complex>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define fi first
#define se second
#define sqr(x) ((x)*(x))
#define odd(x) ((x) % 2 == 1)
#define next(i,n) ((i == n) ? 1 : i + 1)   //1..n
#define prev(i,n) ((i == 1) ? n : i - 1)   //1..n

typedef long long int64;

const int MAXN = (int)1E5+100;
const int INF = (int)1E9;
const long double eps = 1e-5;
const long double pi = 3.1415926535897932384626433832795;

using namespace std;

struct point {
    double x, y;
};

point vec_build(point p1, point p2) {
    point ret;
    ret.x = p2.x - p1.x;
    ret.y = p2.y - p1.y;
    return ret;
}

double vec_len(point p) {
    return sqrt(sqr(p.x) + sqr(p.y));
}

double sc_mul(point p1, point p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

double vec_mul(point p1, point p2) {
    return p1.x * p2.y - p2.x * p1.y;
}

double vec_corner(point p1, point p2) {
    return abs(atan2(vec_mul(p1, p2), sc_mul(p1, p2)));
}

double vec_sqr(point p1, point p2) {
    return abs(vec_mul(p1, p2)) / 2; //S of triangle ;)
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    point a, b, d;
    scanf("%lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &d.x, &d.y);
    point ab = vec_build(a, b), bc = vec_build(b, d), ca = vec_build(d, a);
    double l1 = vec_len(ab), l2 = vec_len(bc), l3 = vec_len(ca);
    double S = (vec_sqr(ab, bc) + vec_sqr(bc, ca) + vec_sqr(ca, ab)) / 3;
    double R = (l1 * l2 * l3) / (4 * S);
    double c[3], p[3];
    c[0] = acos((sqr(l1) + sqr(l2) - sqr(l3)) / (2 * l1 * l2));
    c[1] = acos((sqr(l1) + sqr(l3) - sqr(l2)) / (2 * l1 * l3));
    c[2] = acos((sqr(l2) + sqr(l3) - sqr(l1)) / (2 * l2 * l3));

    double corner;
    int i = 2, sum;
    bool f = 1;
    while (f) {
        i++;
        corner = pi / i;
        sum = 0;
        forn(j, 3) {
            p[j] = round(c[j] / corner);
            sum += p[j];
        }
        if (((sum == i) && (abs(p[0] - c[0] / corner) < eps) && (abs(p[1] - c[1] / corner) < eps) && (abs(p[2] - c[2] / corner) < eps)))
            f = 0;
    }
    double n = i;
    double res = n / 2;
    res *= sqr(R);
    res *= sin(2 * pi / n);
    printf("%.6lf", res);

    return 0;
}