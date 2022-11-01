#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef pair<int, int> pii;

vector<pii> s[2];
int x, y;

bool inside(pii p) {
    int x1 = s[0][0].first, x2 = s[0][2].first;
    int y1 = s[0][0].second, y2 = s[0][2].second;

    if(x1 > x2) swap(x1, x2);
    if(y1 > y2) swap(y1, y2);

    return (x1 <= p.first && p.first <= x2 && y1 <= p.second && p.second <= y2);
}

bool intersec(pii c, pii d) {
    int incx = 1, incy = 1;
    if(c.first > d.first) incx = -1;
    if(c.second > d.second) incy = -1;

    while(c != d) {
        if(inside(c)) return true;
        c.first += incx;
        c.second += incy;
    }
    if(inside(c)) return true;

    return false;
}

int main() {

    for(int j = 0; j < 2; j++) {
        for(int i = 0; i < 4; i++) {
            scanf("%d %d", &x, &y);
            s[j].emplace_back(x, y);
        }
    }

    for(int i = 0; i < 4; i++) {
        if(inside(s[1][i])) {
            puts("YES");
            return 0;
        }
    }

    for(int j = 0; j < 4; j++) {
        if(intersec(s[1][j], s[1][(j+1)%4])) {
            puts("YES");
            return 0;
        }
    }

    for(int i = 0; i < 4; i++) {
        s[0][i] = {s[0][i].first + s[0][i].second, s[0][i].first - s[0][i].second};
        s[1][i] = {s[1][i].first + s[1][i].second, s[1][i].first - s[1][i].second};
    }
    swap(s[0], s[1]);

    for(int i = 0; i < 4; i++) {
        if(inside(s[1][i])) {
            puts("YES");
            return 0;
        }
    }

    puts("NO");
    return 0;
}