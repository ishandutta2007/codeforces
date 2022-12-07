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

int n, m, dx, dy;
int a[1000001];
int cnt[1000000] = {};
bool vis[1000000] = {};

inline int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> dx >> dy;
    int g = gcd(dx, dy);
    dx /= g, dy /= g;
    a[0] = 0;
    int x = 0, y = 0;
    for (int i = 1; i <= n; ++i) {
        x += dx;
        if (x >= n) x -= n;
        y += dy;
        if (y >= n) y -= n;
        a[x] = y;
    }
    REP(i, m) {
        cin >> x >> y;
        int c = y - a[x];
        if (c < 0) c += n;
        ++cnt[c];
    }
    int best = -1, bestind = -1;
    int delta = a[n];
    REP(i, n) if (!vis[i]) {
        int cur = 0;
        int j = i;
        while (!vis[j]) {
            vis[j] = true;
            cur += cnt[j];
            j += delta;
        }
        if (cur > best) {
            best = cur;
            bestind = i;
        }
    }
    cout << 0 << ' ' << bestind << '\n';
    return 0;
}