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
int x[100001], y[100001];
LL s[100000];
int cnt[100000];
int cx, cy;
double tot = -1;
double p[200];

LL getS(int x, int y, int xx, int yy) {
    return (LL)x * yy - (LL)y * xx;
}

int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

int main() {
    p[0] = 1;
    for (int i = 1; i < 200; ++i) p[i] = p[i - 1] * 2;
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", x + i, y + i);
    cx = x[n] = x[0];
    cy = y[n] = y[0];
    REP(i, n) s[i] = getS(x[i] - cx, y[i] - cy, x[i + 1] - cx, y[i + 1] - cy);
    REP(i, n) cnt[i] = gcd(abs(x[i + 1] - x[i]), abs(y[i + 1] - y[i]));
    if (n <= 100) {
        tot = p[n] - (n * (n + 1) * 0.5 + 1);
    }
    double ans = 0;
    REP(i, n) {
        LL sumS = s[i];
        LL sumC = cnt[i];
        for (int z = 1; z < min(70, n - 2); ++z) {
            int j = (i + z) % n;
            sumS += s[j];
            sumC += cnt[j];
            LL cur = abs(sumS + getS(x[j + 1] - cx, y[j + 1] - cy, x[i] - cx, y[i] - cy));
            cur -= sumC;
            cur += gcd(abs(x[i] - x[j + 1]), abs(y[i] - y[j + 1]));
            if (n <= 100) {
                ans += cur * (p[n - z - 2] - 1) / tot;
            } else {
                ans += cur / p[z + 2];
            }
        }
    }
    LL sum = 0, c = 0;
    REP(i, n) sum += s[i];
    REP(i, n) c += cnt[i];
    ans = (double(abs(sum) - c + 2) - ans) * 0.5;
    printf("%.15f\n", ans);
    return 0;
}