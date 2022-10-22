#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;
#define int long long

struct Point {
    int x, y;
};

Point Pinit(int x, int y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

struct Vector {
    int x, y;
};

Vector Vinit(Point a, Point b) {
    Vector v;
    v.x = b.x - a.x;
    v.y = a.y - b.y;
    return v;
}

int cp(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

bool check(vector <Point> a) {
    for (int i = 2; i < (int)a.size(); ++i) {
        if (cp(Vinit(a[0], a[1]), Vinit(a[0], a[i]))) return false;
    }
    return true;
}

bool check1(vector <Point> a, Point x, Point y) {
    vector <Point> b;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (cp(Vinit(x, y), Vinit(x, a[i]))) b.push_back(a[i]);
    }
    return check(b);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector <Point> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;

    if (n <= 4) {
        cout << "YES\n";
        return 0;
    }

    if (check1(a, a[0], a[1])) {
        cout << "YES\n";
        return 0;
    }

    if (check1(a, a[0], a[2])) {
        cout << "YES\n";
        return 0;
    }

    if (check1(a, a[1], a[2])) {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";
    return 0;
}