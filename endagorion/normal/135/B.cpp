#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

#ifndef ONLINE_JUDGE

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);
FILE *file_in = fopen("input.txt", "rt");
FILE *file_out = fopen("output.txt", "wt");

#else

#define fin cin
#define fout cout
#define file_in stdin
#define file_out stdout

#endif

struct TPoint {
    int x, y, i;

    TPoint()
        : x(0)
        , y(0)
        , i(0)
    {
    }

    TPoint(int _x, int _y, int _i = 0) 
        : x(_x)
        , y(_y)
        , i(_i)
    {
    }

    TPoint operator-(const TPoint &p) const {
        return TPoint(x - p.x, y - p.y);
    }

    int dot(const TPoint &p) const {
        return x * p.x + y * p.y;
    }

    int d2() const {
        return dot(*this);
    }

    bool operator==(const TPoint &p) const {
        return x == p.x && y == p.y;
    }

    bool operator!=(const TPoint &p) const {
        return !(*this == p);
    }

    bool operator<(const TPoint &p) const {
        if (x != p.x) {
            return x < p.x;
        }
        return y < p.y;
    }
};

bool areSquare(vector< TPoint > points) {
    if (points.size() != 4) {
        return false;
    }
    bool ok = true;
    for (int i = 0; i < 4; ++i) {
        if ((points[i] - points[(i + 3) % 4]).dot(points[i] - points[(i + 1) % 4]) != 0) {
            ok = false;
            break;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if ((points[i] - points[(i + 3) % 4]).d2() != (points[i] - points[(i + 1) % 4]).d2()) {
            ok = false;
            break;
        }
    }
    return ok;
}

bool areRect(vector< TPoint > points) {
    if (points.size() != 4) {
        return false;
    }
    bool ok = true;
    for (int i = 0; i < 4; ++i) {
        if ((points[i] - points[(i + 3) % 4]).dot(points[i] - points[(i + 1) % 4]) != 0) {
            ok = false;
            break;
        }
    }
    return ok;
}

int main() {        
    vector< TPoint > points(8);
    for (int i = 0; i < 8; ++i) {
        fin >> points[i].x >> points[i].y;
        points[i].i = i;
    }

    sort(points.begin(), points.end());
    while (true) {
        vector< TPoint > first(points.begin(), points.begin() + 4);
        vector< TPoint > second(points.begin() + 4, points.begin() + 8);
        if (areSquare(first) && areRect(second)) {
            fout << "YES\n";
            for (int i = 0; i < 4; ++i) {
                fout << first[i].i + 1 << ' ';
            }
            fout << '\n';
                for (int i = 0; i < 4; ++i) {
                fout << second[i].i + 1 << ' ';
            }
            fout << '\n';
            return 0;
        }
        if (!next_permutation(points.begin(), points.end())) {
            break;
        }
    }

    fout << "NO\n";
    return 0;
}