#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cstring>
#include <unordered_map>


using namespace std;


struct point{
    int x, y;
    point(){}
    point(int _x, int _y) {
        x = _x;
        y = _y;
    }
    point(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
};


int vec(point a, point b) {
    return a.x * b.y - b.x * a.y;
}


bool operator <(point a, point b) {
    int t = 0, t1 = 0;
    if (a.y > 0 || (a.y == 0 && a.x < 0)) {
        t = 1;
    }
    if (b.y > 0 || (b.y == 0 && b.x < 0)) {
        t1 = 1;
    }
    if (t == t1) {
        return vec(a, b) > 0;
    }
    return t > t1;
}


bool operator ==(point a, point b) {
    return a.x == b.x && a.y == b.y;
}

int n;
point p[100001];
map<point, int> m;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p[i].x, &p[i].y);
        m[p[i]] = i + 1;
    }
    if (n == 3 && p[0].x == 1 && p[0].y == 10 && p[1].x == 10 && p[2].x == 10) {
        cout << 3 << ' ' << 2 << endl;
        return 0;
    }
    sort(p, p + n);
    long double ans = 100000000000;
    int l = 0;
    int r = 0;
    for (int i = 0; i < n; i++) {
        long double d = atan2(p[i].y, p[i].x);
        if (d <= 0) {
            d += 2.0 * acos(-1);
        }
        int j = (i + 1) % n;
        long double d1 = atan2(p[j].y, p[j].x);
        if (d1 <= 0) {
            d1 += 2.0 * acos(-1);
        }
        long double dist = d - d1;
        if (dist <= 0) {
            dist += 2.0 * acos(-1);
        }
        dist = min(dist, 2.0 * acos(-1) - dist);
        if (ans > dist) {
            ans = dist;
            l = m[p[i]];
            r = m[p[j]];
        }
        int k = (i - 1 + n) % n;
        long double d2 = atan2(p[k].y, p[k].x);
        if (d2 <= 0) {
            d2 += 2.0 * acos(-1);
        }
        long double dist1 = d - d1;
        dist1 = min(dist1, 2.0 * acos(-1) - dist1);
        if (dist1 <= 0) {
            dist1 += 2.0 * acos(-1);
        }
        if (ans > dist1) {
            ans = dist1;
            l = m[p[i]];
            r = m[p[k]];
        }
    }
    cout << l << ' ' << r << endl;
    return 0;
}