#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long double ld;
const int N = 10001;
ld sqr(ld x) {
    return x*x;
}
struct point{
    ld x, y;
    point(ld x = 0, ld y = 0):x(x), y(y){}
    ld len(){
        return sqrtl(sqr(x) + sqr(y));
    }
}a[N], O, b[2], nowO;
int id[2];

ld dis(point a, point b) {
    return sqrtl(sqr(a.x - b.x)+ sqr(a.y - b.y));
}
ld operator*(point a, point b) {
    return a.x * b.y - a.y * b.x;
}
point operator+(point a, point b) {
    return point(a.x + b.x, a.y + b.y);
}
point operator-(point a, point b) {
    return point(a.x - b.x, a.y - b.y);
}
point operator*(point a, ld b) {
    return point(a.x * b, a.y * b);
}
point operator/(point a, ld b) {
    return point(a.x / b, a.y / b);
}
ld cross(point a, point b, point c) {
    return (b - a) * (c - a);
}
point rotate(point a, ld w){
    return point(cosl(w)  * a.x - sinl(w) * a.y, sinl(w) * a.x + cosl(w) * a.y);
}
ld dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

ld angle(point a, point b) {
    return acosl(max(min(dot(a, b) / (a.len() * b.len()), (ld)1), (ld)-1));
}
int n, m;
point get(point nowO, point p, int pid, int toid) {
    if (pid == toid) return p;
    p = p - nowO;
    point A = a[pid] - O, B = a[toid] - O;
    ld w = angle(A, B);
    if (A * B < 0) {
        return nowO + (rotate(p,-w) / A.len() * B.len());
    } else
        return nowO + (rotate(p,w) / A.len() * B.len());
}
int main(){
    scanf("%d %d", &n, &m);
    for (int i= 1; i <= n; i ++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        a[i] = point(x, y);
    }
    ld area = 0;
    for (int i = 2; i < n; i ++) {
        O = O +((a[1] + a[i] + a[i + 1]) / 3 * cross(a[1], a[i], a[i + 1]));
        area += cross(a[1], a[i], a[i + 1]);
    }
    O = O / area;
    id[0] = 1;
    id[1] = 2;
    b[0] = a[1];
    b[1] = a[2];
    nowO = O;
    while (m --) {
        int sig, x, y;
        scanf("%d %d", &sig, &x);
        if (sig == 1) {
            scanf("%d", &y);
            if (x == id[1]) {
                swap(b[0], b[1]);
                swap(id[0], id[1]);
            }
            nowO = b[1] - point(0, dis(O, a[id[1]]));
            id[0] = y;
            b[0] = get(nowO, b[1], id[1], id[0]);
        } else {
            point a = get(nowO, b[1], id[1], x);
            printf("%.10f %.10f\n", (double)a.x, (double) a.y);
        }
    }
    return 0;
}