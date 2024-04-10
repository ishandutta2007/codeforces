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

struct E {
    int to, gcd, lcm;
    E(int to, int gcd, int lcm) : to(to), gcd(gcd), lcm(lcm) {}
    E() {}
};

int n, m;
vector<E> g[100];
int ans[100];

int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

bool dfs(int v, int val) {
    if (ans[v] != -1) return ans[v] == val;
    ans[v] = val;
    for (E e : g[v]) {
        LL newVal = (LL)e.gcd * e.lcm;
        if (newVal % val != 0) return false;
        newVal /= val;
        if (newVal > 1000000) return false;
        int g = gcd(val, newVal);
        LL l = (LL)val * newVal / g;
        if (g != e.gcd || l != e.lcm) return false;
        if (!dfs(e.to, newVal)) return false;
    }
    return true;
}

void cl(int v) {
    ans[v] = -1;
    for (E e : g[v]) if (ans[e.to] != -1) {
        cl(e.to);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int from, to, gg, l;
        scanf("%d%d%d%d", &from, &to, &gg, &l), --from, --to;
        if (l % gg != 0) {
            printf("NO\n");
            return 0;
        }
        g[from].pb(E(to, gg, l));
        g[to].pb(E(from, gg, l));
    }
    REP(i, n) ans[i] = -1;
    REP(i, n) if (ans[i] == -1) {
        if (g[i].empty()) {
            ans[i] = 1;
            continue;
        }
        int gg = g[i][0].gcd;
        int l = g[i][0].lcm;
        int x = l / gg;
        vector<int> p;
        for (int i = 2; i * i <= x; ++i) if (x % i == 0) {
            int mul = i;
            x /= i;
            while (x % i == 0) {
                mul *= i;
                x /= i;
            }
            p.pb(mul);
        }
        if (x > 1) {
            p.pb(x);
        }
        int sz = (int)p.size();
        REP(mask, 1 << sz) {
            int val = gg;
            REP(i, sz) if (mask & (1 << i)) {
                val *= p[i];
            }
            bool ok = true;
            if (!dfs(i, val)) {
                cl(i);
                if (!dfs(i, val)) {
                    ok = false;
                    cl(i);
                }
            }
            if (ok) break;
        }
        if (ans[i] == -1) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    REP(i, n) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}