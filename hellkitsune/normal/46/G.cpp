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
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<PII> v;
int y = 0, x = 0;
const double PI = atan2(0, -1);

inline int len2(const PII &x) {
    return x.first * x.first + x.second * x.second;
}

inline bool cmp(const PII &lhs, const PII &rhs) {
    return len2(lhs) < len2(rhs);
}

inline bool eq(const PII &lhs, const PII &rhs) {
    return len2(lhs) == len2(rhs);
}

inline bool cmp2(const PII &lhs, const PII &rhs) {
    double l = atan2(lhs.first, lhs.second);
    double r = atan2(rhs.first, rhs.second);
    if (l < 0) l += 2 * PI;
    if (r < 0) r += 2 * PI;
    return l < r;
}

int main() {
    REP(i, 300) for (int j = i; j < 300; ++j) if (i || j) v.pb(mp(i, j));
    sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(), v.end(), eq), v.end());
    scanf("%d", &n);
    printf("YES\n");
    if (n == 3) {
        printf("0 0\n1 0\n0 2\n");
        return 0;
    }
    REP(i, n) y += v[i].first, x += v[i].second;
    if ((y + x) % 2 == 1) {
        REP(j, n) if (((v[j].first + v[j].second) ^ (v[n].first + v[n].second)) & 1) {
            y += v[n].first - v[j].first;
            x += v[n].second - v[j].second;
            v[j] = v[n];
            break;
        }
    }
    assert((x + y) % 2 == 0);
    int tt = 300;
    while (y + x != 0) {
        int bestx = 0, besty = 0;
        for (int i = 1; i < n; ++i) if (abs(y + x - 2 * v[i].first) < abs(y + x - 2 * v[besty].first)) {
            besty = i;
        }
        for (int i = 1; i < n; ++i) if (abs(y + x - 2 * v[i].second) < abs(y + x - 2 * v[bestx].second)) {
            bestx = i;
        }
        if (++tt % 10 == 9) {
            bestx = (tt / 10 * 1007 + 123) % n;
            besty = (tt / 10 * 1009 + 321) % n;
        }
        if (abs(y + x - 2 * v[besty].first) < abs(y + x - 2 * v[bestx].second)) {
            y -= 2 * v[besty].first;
            v[besty].first *= -1;
        } else {
            x -= 2 * v[bestx].second;
            v[bestx].second *= -1;
        }
    }
    tt = 300;
    while (y != 0) {
        int best = 0;
        for (int i = 1; i < n; ++i) if (abs(y - v[i].first + v[i].second) < abs(y - v[best].first + v[best].second)) {
            best = i;
        }
        if (++tt % 10 == 9) {
            best = (tt / 10 * 1007 + 123) % n;
        }
        y -= v[best].first - v[best].second;
        swap(v[best].first, v[best].second);
    }
    v.resize(n);
    sort(v.begin(), v.end(), cmp2);
    for (int i = 1; i < n; ++i) {
        v[i].first += v[i - 1].first;
        v[i].second += v[i - 1].second;
    }
    printf("0 0\n");
    REP(i, n - 1) printf("%d %d\n", v[i].second, v[i].first);
    return 0;
}