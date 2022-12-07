#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

struct S {
    int x1, y1, x2, y2;
};

LL scal(LL x1, LL y1, LL x2, LL y2) {
    return x1 * x2 + y1 * y2;
}

LL skew(LL x1, LL y1, LL x2, LL y2) {
    return x1 * y2 - x2 * y1;
}

bool check (S s, int x, int y) {
    if ((x == s.x1 || x == s.x2) && s.x1 != s.x2) return false;
    if ((y == s.y1 || y == s.y2) && s.y1 != s.y2) return false;
    if (LL(x - s.x1) * (s.y2 - s.y1) != LL(y - s.y1) * (s.x2 - s.x1)) return false;
    if (LL(x - s.x1) * (s.x2 - x) < 0) return false;
    if (LL(y - s.y1) * (s.y2 - y) < 0) return false;
    if (x - s.x1 > 0) {
        if ((x - s.x1) * 4 < (s.x2 - x)) return false;
        if ((s.x2 - x) * 4 < (x - s.x1)) return false;
    } else if (x - s.x1 < 0) {
        if ((s.x1 - x) * 4 < (x - s.x2)) return false;
        if ((x - s.x2) * 4 < (s.x1 - x)) return false;
    }
    if (y - s.y1 > 0) {
        if ((y - s.y1) * 4 < (s.y2 - y)) return false;
        if ((s.y2 - y) * 4 < (y - s.y1)) return false;
    } else if (y - s.y1 < 0) {
        if ((s.y1 - y) * 4 < (y - s.y2)) return false;
        if ((y - s.y2) * 4 < (s.y1 - y)) return false;
    }
    return true;
}

bool solve(S s1, S s2, S s3) {
    if (s1.x1 == s2.x2 && s1.y1 == s2.y2) {
        swap(s2.x2, s2.x1);
        swap(s2.y2, s2.y1);
    }
    if (s1.x2 == s2.x1 && s1.y2 == s2.y1) {
        swap(s1.x2, s1.x1);
        swap(s1.y2, s1.y1);
    }
    if (s1.x2 == s2.x2 && s1.y2 == s2.y2) {
        swap(s2.x2, s2.x1);
        swap(s2.y2, s2.y1);
        swap(s1.x2, s1.x1);
        swap(s1.y2, s1.y1);
    }
    if (s1.x1 != s2.x1 || s1.y1 != s2.y1) return false;
    if (scal(s1.x2 - s1.x1, s1.y2 - s1.y1, s2.x2 - s2.x1, s2.y2 - s2.y1) < 0) return false;
    if (skew(s1.x2 - s1.x1, s1.y2 - s1.y1, s2.x2 - s2.x1, s2.y2 - s2.y1) == 0) return false;
    return (check(s1, s3.x1, s3.y1) && check(s2, s3.x2, s3.y2)) ||
           (check(s2, s3.x1, s3.y1) && check(s1, s3.x2, s3.y2));
}

S s[3];

int main() {
    int t;
    scanf("%d", &t);
    REP(test, t) {
        REP(i, 3) scanf("%d%d%d%d", &s[i].x1, &s[i].y1, &s[i].x2, &s[i].y2);
        bool flag = solve(s[0], s[1], s[2]) || solve(s[0], s[2], s[1]) || solve(s[1], s[2], s[0]);
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}