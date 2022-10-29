#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5;
struct point{
    long long x, y;
    point(long long x=  0, long long y = 0) :x(x), y(y){}
    long long len2() {
        return x * x + y * y;
    }
}a[N];
int d[N];
long long operator*(point a, point b) {
    return a.x * b.y - a.y * b.x;
}
point operator+(point a, point b) {
    return point(a.x + b.x, a.y + b.y);
}
point operator-(point a, point b) {
    return point(a.x - b.x, a.y - b.y);
}
point p2seg_central_symmetry(point p, point s1, point s2) {//
    return point(s1.x + s2.x -p.x, s1.y + s2.y - p.y);
}
long long cross(point a, point b, point c) {
    return (b - a) * (c - a);
}
void graham(point*a, int&n) { // 
    for (int i = 1; i < n; i ++)
        if (a[i].y < a[0].y || (a[i].y == a[0].y && a[i].x < a[0].x)) swap(a[0], a[i]);
    point st = a[0];
    for (int i = 0; i < n; i ++)
        a[i] = a[i] - st;
    sort(a + 1, a + n, [](point a,point b) {
        long long v = a* b;
        return v > 0 || (v == 0 && a.len2() < b.len2());
    });
    d[0] = 1;
    d[1] = 0;
    for (int i = 1; i < n ; d[++d[0]] = i, i++)
        while (d[0] > 2 && (a[d[d[0]]] - a[d[d[0] - 1]]) * (a[i] - a[d[d[0] - 1]]) <= 0)/**/ d[0] --;
    for (int i = 1; i <= d[0]; i ++)
        a[i - 1] = a[d[i]] + st;
    n = d[0];
}

vector<point> get_bigest_triangle(vector<point>a) {//()
    long long v = 0;
    int x, y, z;
    for (int i = 0; i < a.size(); i ++) {
        int l = i, r = (i + 1) % a.size();
        for (int j = 1; j < a.size(); j ++) {
            int mid = (j + i) % a.size();
            while (l != mid && cross(a[i], a[l], a[mid]) <= cross(a[i], a[(l + 1) % a.size()], a[mid])) l = (l + 1) % a.size();
            while (r != i && cross(a[i], a[mid], a[r]) <= cross(a[i], a[mid], a[(r + 1) % a.size()])) r = (r + 1) % a.size();
            if (cross(a[i], a[l], a[mid]) > v) {
                v = cross(a[i], a[l], a[mid]);
                x = i, y = mid, z = l;
            }
            if (cross(a[i], a[mid], a[r]) > v) {
                v = cross(a[i], a[mid], a[r]);
                x = i, y = mid , z = r;
            }
            if (r == mid)
                r = (r + 1) % a.size();
        }
    }
    return {a[x], a[y], a[z]};
}
int n;
vector<point> b;
int main() {
    long long s;
    scanf("%d %lld", &n, &s);
    for (int i = 0; i < n; i ++)
        scanf("%lld %lld", &a[i].x, &a[i].y);
    graham(a, n);
    for (int i = 0; i < n; i ++)
        b.push_back(a[i]);
    auto u = get_bigest_triangle(b);
    point up = p2seg_central_symmetry(u[0], u[1], u[2]);
    u[1] = u[1] + u[1] - up;
    u[2] = u[2] + u[2] - up;
    printf("%lld %lld\n", u[1].x, u[1].y);
    printf("%lld %lld\n", u[2].x, u[2].y);
    printf("%lld %lld\n", up.x, up.y);
    return 0;
}