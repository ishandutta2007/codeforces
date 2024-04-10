#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>


using namespace std;


struct point{
    int x, y, s;
    point(){}
    point(int _x, int _y, int _s) {
        x = _x;
        y = _y;
        s = _s;
    }
};


bool les (const point& a, const point& b) {
    return sqrt(a.x * a.x + a.y * a.y) < sqrt(b.x * b.x + b.y * b.y);
}


int n, s;
point p[100000];
int a[100000];


int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y >> p[i].s;
    }
    sort(p, p + n, les);
    int i = 0;
    int l = s;
    while (i < n && l < 1000000) {
        l += p[i].s;
        i++;
    }
    if (l < 1000000) {
        cout << -1 << endl;
        return 0;
    } else {
        printf("%.10lf\n", sqrt(p[i - 1].x * p[i - 1].x + p[i - 1].y * p[i - 1].y));
    }
    return 0;
}