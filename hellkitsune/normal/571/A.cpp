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

int a, b, c, l;

LL halp(int mx, int b, int c, int len) {
    if (len < 0) return 0;
    if (b > mx || c > mx) return 0;
    b = mx - b;
    c = mx - c;
    if (b > len) {
        ++len, ++c;
        LL ret = (LL)len * (len + 1) / 2;
        if (c < len) {
            c = len - c;
            ret -= (LL)c * (c + 1) / 2;
        }
        return ret;
    }
    if (c > len) {
        ++len, ++b;
        LL ret = (LL)len * (len + 1) / 2;
        if (b < len) {
            b = len - b;
            ret -= (LL)b * (b + 1) / 2;
        }
        return ret;
    }
    LL ret = LL(b + 1) * (c + 1);
    if (b + c > len) {
        int sz = b + c - len;
        ret -= (LL)sz * (sz + 1) / 2;
    }
    return ret;
}

LL solve(int a, int b, int c) {
    LL ans = 0;
    for (int i = 0; i <= l; ++i) {
        if (a + i < b + c + l - i) {
            ans += halp(a + i - 1, b, c, l - i);
            ans -= halp(a + i - 1, b, c, a + i - b - c);
        }
    }
    return ans;
}

LL solve2(int a, int b, int c) {
    LL ans = 0;
    for (int x = max(a, b); 2 * x - a - b <= l; ++x) {
        int mx = min(c + l - (2 * x - a - b), x - 1);
        int mn = c;
        if (mx >= mn) {
            ans += mx - mn + 1;
        }
    }
    return ans;
}

LL solve3(int a, int b, int c) {
    LL ans = 0;
    for (int x = max(max(a, b), c); 3 * x - a - b - c <= l; ++x) {
        ++ans;
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d", &a, &b, &c, &l);
    LL ans = 0;
    ans += solve(a, b, c);
    ans += solve(b, a, c);
    ans += solve(c, a, b);
    ans += solve2(a, b, c);
    ans += solve2(a, c, b);
    ans += solve2(b, c, a);
    ans += solve3(a, b, c);
    cout << ans << endl;
    return 0;
}