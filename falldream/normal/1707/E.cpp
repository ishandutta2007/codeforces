#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define MM 30
#define MX 16
#define MN 100000
using namespace std;
// my fast read template
inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

int n, q, fl[MM + 1][MN + 5], fr[MM + 1][MN + 5], a[MN + 5], llog[MN + 5];

struct BIT {
    int mn[MX + 1][MN + 5], mx[MX + 1][MN + 5], lev;
    void build(int *s1, int *s2, int len) {
        for (int i = 1; i <= len; ++i) {
            mn[0][i] = s1[i];
            mx[0][i] = s2[i];
        }
        lev = llog[len];
        for (int k = 1; k <= lev; ++k) {
            int h = 1 << (k - 1);
            for (int i = len - (1 << k) + 1; i; --i) {
                mn[k][i] = min(mn[k - 1][i], mn[k - 1][i + h]);
                mx[k][i] = max(mx[k - 1][i], mx[k - 1][i + h]);
            }
        }
    }
    pair<int, int> query(int l, int r) {
        if (l > r) return make_pair(1000000001, 0);
        int k = llog[r - l + 1], L = 1 << k;
        return make_pair(min(mn[k][l], mn[k][r - L + 1]),
                         max(mx[k][l], mx[k][r - L + 1]));
    }
}b[MM + 1];

int main() {
    n = read(); q = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 1; i <= n; ++i) {
        llog[i] = llog[i - 1];
        if (i >= (1 << (llog[i] + 1))) ++ llog[i];
    }
    for (int i = 1; i < n; ++i) fl[0][i] = min(a[i], a[i + 1]), fr[0][i] = max(a[i], a[i + 1]) - 1;
    for (int k = 1; k <= MM; ++k) {
        b[k - 1].build(fl[k - 1], fr[k - 1], n - 1);
        for (int i = 1; i < n; ++i) {
            pair<int, int> p = b[k - 1].query(fl[k - 1][i], fr[k - 1][i]);
            fl[k][i] = p.first;
            fr[k][i] = p.second;
        }
    }
    b[MM].build(fl[MM], fr[MM], n - 1);
    for (int i = 1; i <= q; ++i) {
        int l = read(), r = read();
        if (l == r) {
            puts(n == 1 ? "0" : "-1");
            continue;
        } else if (l == 1 && r == n) {
            puts("0");
            continue;
        } else {
            --r;
        }

        int ans = 0;
        for (int k = MM; ~k; --k) {
            pair<int, int> p = b[k].query(l, r);
            // printf("%d %d %d\n", k, p.first, p.second);
            if (p.first >= n || p.second <= 0) {
                ans = -1;
                break;
            }
            if (p.first != 1 || p.second != n - 1) {
                if (k == MM) {
                    ans = -1;
                    break;
                } else {
                    ans += 1 << k;
                    l = p.first, r = p.second;
                }
            }
        }
        if (ans != -1 && (l != 1 || r != n - 1)) {
            ++ ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}