#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y): x(x), y(y) {}

    void read() {
        scanf("%d%d", &x, &y);
    }
};

bool operator ==(const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}

Point operator +(const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
}

int det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

int sqr(int x) {
    return x * x;
}

int dist(const Point &a, const Point &b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

Point p[11];

int getID(const Point &a) {
    for (int i = 0; i < 8; ++ i) {
        if (p[i] == a) {
            return i + 1;
        }
    }
    return 0;
}

bool isRect(Point rect[]) {
    int perm[11];
    for (int i = 0; i < 4; ++ i) {
        perm[i] = i;
    }
    do {
        bool okay = true;
        int area = 0;
        for (int i = 0; i < 4; ++ i) {
            area += det(rect[perm[i]], rect[perm[(i + 1) % 4]]);
        }
        if (area == 0) {
            okay = false;
        } else {
            okay &= rect[perm[0]] + rect[perm[2]] 
                == rect[perm[1]] + rect[perm[3]];
            okay &= dist(rect[perm[0]], rect[perm[2]]) 
                == dist(rect[perm[1]], rect[perm[3]]);
        }
        if (okay) {
            return true;
        }
    } while (next_permutation(perm, perm + 4));
    return false;
}

bool isSqr(Point sqr[]) {
    if (!isRect(sqr)) {
        return false;
    }
    int perm[11];
    for (int i = 0; i < 4; ++ i) {
        perm[i] = i;
    }
    do {
        bool okay = true;
        int len = dist(sqr[perm[0]], sqr[perm[3]]);
        for (int i = 0; i < 3; ++ i) {
            okay &= dist(sqr[perm[i]], sqr[perm[i + 1]]) == len;
        }
        if (okay) {
            return true;
        }
    } while (next_permutation(perm, perm + 4));
    return false;
}

int main() {
    for (int i = 0; i < 8; ++ i) {
        p[i].read();
    }
    for (int mask = 0; mask < (1 << 8); ++ mask) {
        int sqrCnt = 0;
        int rectCnt = 0;
        Point sqr[11], rect[11];
        for (int i = 0; i < 8; ++ i) {
            if ((mask >> i) & 1) {
                sqr[sqrCnt ++] = p[i];
            } else {
                rect[rectCnt ++] = p[i];
            }
        }
        if (sqrCnt == 4 && isSqr(sqr) && isRect(rect)) {
            puts("YES");
            for (int i = 0; i < 4; ++ i) {
                printf("%d%c", getID(sqr[i]), i == 3? '\n': ' ');
            }
            for (int i = 0; i < 4; ++ i) {
                printf("%d%c", getID(rect[i]), i == 3? '\n': ' ');
            }
            return 0;
        }
    }
    puts("NO");
    return 0;
}