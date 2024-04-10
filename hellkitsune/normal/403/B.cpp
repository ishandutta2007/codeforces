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
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int a[5000], b[5000];
bool pr[32000];
vector<int> p;
bool badP[32000] = {};
set<int> badSe;
int g[5000];

int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

int divEval(int x) {
    int ret = 0;
    for (int pr : p) while (x % pr == 0) {
        x /= pr;
        if (badP[pr]) {
            --ret;
        } else {
            ++ret;
        }
    }
    if (x > 1) {
        if (badSe.count(x)) {
            --ret;
        } else {
            ++ret;
        }
    }
    return ret;
}

int main() {
    REP(i, 32000) pr[i] = true;
    for (int i = 2; i < 200; ++i) if (pr[i]) {
        for (int j = i * i; j < 32000; j += i) {
            pr[j] = false;
        }
    }
    for (int i = 2; i < 32000; ++i) if (pr[i]) {
        p.pb(i);
    }
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", a + i);
    REP(i, m) scanf("%d", b + i);
    REP(i, m) {
        badSe.insert(b[i]);
        if (b[i] < 32000) {
            badP[b[i]] = true;
        }
    }
    g[0] = a[0];
    for (int i = 1; i < n; ++i) {
        g[i] = gcd(g[i - 1], a[i]);
    }
    int d = 1, ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (divEval(g[i] / d) < 0) {
            d = g[i];
        }
        a[i] /= d;
        ans += divEval(a[i]);
    }
    printf("%d\n", ans);
    return 0;
}