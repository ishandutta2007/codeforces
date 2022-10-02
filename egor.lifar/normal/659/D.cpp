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
    cout << (n - 4) / 2 << endl;
    return 0;
}