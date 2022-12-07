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

int n;
int x[2000], y[2000];
int mac = 0;
int rev[4000001];
map<LL, int> ma;

int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

inline LL C3(int x) {
    if (x < 3) return 0;
    return (x * 1ll * (x - 1) * 1ll * (x - 2)) / 6;
}

int main() {
    REP(i, 4000001) rev[i] = -1;
    for (int i = 1, j = 1; j <= 4000000; ++i, j += i) {
        rev[j] = i;
    }
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", x + i, y + i);
    REP(i, n) for (int j = i + 1; j < n; ++j) {
        int a = y[i] - y[j];
        int b = x[j] - x[i];
        int g = gcd(abs(a), abs(b));
        a /= g;
        b /= g;
        if (a == 0) b = 1;
        else if (b == 0) a = 1;
        else if (a < 0) {
            a = -a;
            b = -b;
        }
        int c = -(a * x[i] + b * y[i]);
        a += 200;
        b += 200;
        c += 40000;
        ++ma[(LL)a | ((LL)b << 10) | ((LL)c << 20)];
    }
    LL ans = C3(n);
    for (auto x : ma) {
        int cnt = rev[x.second];
        assert(cnt != -1);
        ans -= C3(cnt + 1);
    }
    cout << ans << endl;
    return 0;
}