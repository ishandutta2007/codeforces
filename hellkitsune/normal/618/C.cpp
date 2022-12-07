#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int x[100000], y[100000];
LL d[100000];
int ord[100000];

LL dist(int x, int y) {
    return (LL)x * x + (LL)y * y;
}

inline bool cmp(const int &lhs, const int &rhs) {
    return d[lhs] < d[rhs];
}

int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

PII getP(int x, int y) {
    int g = gcd(abs(x), abs(y));
    x /= g;
    y /= g;
    if (x == 0) {
        y = 1;
    } else if (y == 0) {
        x = 1;
    } else if (x < 0) {
        x = -x;
        y = -y;
    }
    return mp(x, y);
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", x + i, y + i);
    REP(i, n) d[i] = dist(x[0] - x[i], y[0] - y[i]);
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    for (int i = 2; i < n; ++i) {
        if (getP(x[ord[1]] - x[0], y[ord[1]] - y[0]) != getP(x[ord[i]] - x[0], y[ord[i]] - y[0])) {
            printf("%d %d %d\n", 1, ord[1] + 1, ord[i] + 1);
            return 0;
        }
    }
    return 0;
}