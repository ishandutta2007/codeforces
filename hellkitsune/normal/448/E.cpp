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

LL x, k;
vector<LL> f;

void go(LL x, LL k, int &lim) {
    if (k == 0 || x == 1) {
        printf("%I64d ", x);
        --lim;
        return;
    }
    REP(i, f.size()) {
        if (f[i] > x) return;
        if (x % f[i] != 0) continue;
        go(f[i], k - 1, lim);
        if (lim == 0) return;
    }
}

int main() {
    cin >> x >> k;
    for (LL i = 1; i * i <= x; ++i) if (x % i == 0) {
        f.pb(i);
        if (i * i != x) f.pb(x / i);
    }
    sort(f.begin(), f.end());
    int lim = 100000;
    go(x, k, lim);
    return 0;
}