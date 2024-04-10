#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


struct point
{
    long long x, y;
    point(){}
    point(long long _x, long long _y) {
        x = _x;
        y = _y;
    }
    point(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
};


long long vec(point a, point b) {
    return a.x * b.y - a.y * b.x;
}


long long scal(point a, point b) {
    return a.x * b.x + a.y * b.y;
}


int n;
point p[100001];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%I64d %I64d", &p[i].x, &p[i].y);
    }
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (p[i].y < p[t].y) {
            t = i;
        } else {
            if (p[i].y == p[t].y && p[i].x < p[t].x) {
                t = i;
            }
        }
    }
    int t1 = 0;
    for (int i = 0; i < n; i++) {
        if ((p[i].y < p[t1].y || t1 == t) && i != t) {
            t1 = i;
        } else {
            if (p[i].y == p[t1].y && p[i].x < p[t1].x && i != t) {
                t1 = i;
            }
        }
    }
    int t2 = -1;
    for (int i = 0; i < n; i++) {
        if (i != t && i != t1) {
            if (vec(point(p[t], p[t1]), point(p[t], p[i])) == 0LL) {
                continue;
            }
            if (t2 == -1 || p[i].y < p[t2].y) {
                t2 = i;
            } else {
                if (p[i].y == p[t2].y && p[i].x < p[t2].x) {
                    t2 = i;
                }
            }
        }
    }
    cout << t + 1 << ' ' << t1 + 1 << ' ' << t2 + 1 << endl;
    return 0;   
}