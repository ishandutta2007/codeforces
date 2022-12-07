#include <cstdio>
#include <cmath>
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

int n, m;
string s[2];
int ty[200000], ty2[200000], dead[200000], cnt[200000], t[200000];
int tx[200000], tx2[200000];

int main() {
    cin >> n >> m;
    cin >> s[0] >> s[1];
    REP(i, n) {
        t[i] = 0;
        if (s[0][i] == 'X')
            t[i] |= 1;
        if (s[1][i] == 'X')
            t[i] |= 2;
    }
    int last = 0, lastx = -1;
    REP(i, n) {
        if (t[i] != 0) {last = t[i]; lastx = i;}
        ty2[i] = last;
        tx2[i] = lastx;
    }
    last = 0; lastx = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (t[i] != 0) {last = t[i]; lastx = i;}
        ty[i] = last;
        tx[i] = lastx;
    }
    dead[0] = (t[0] == 3);
    cnt[0] = 0;
    last = t[0];
    for (int i = 1; i < n; ++i) {
        dead[i] = dead[i - 1];
        cnt[i] = cnt[i - 1];
        if ((t[i] | t[i - 1]) == 3)
            ++dead[i];
        if ((t[i] | last) == 3 && t[i] != 0)
            ++cnt[i];
        if (t[i] != 0)
            last = t[i];
    }
    REP(q, m) {
        int x, y;
        int rx = 1, ry = 1;
        scanf("%d%d", &x, &y);
        if (x > n) {
            x -= n;
            rx = 2;
        }
        if (y > n) {
            y -= n;
            ry = 2;
        }
        --x; --y;
        if (x > y) {
            x ^= y; rx ^= ry;
            y ^= x; ry ^= rx;
            x ^= y; rx ^= ry;
        }
        if (dead[y] > dead[x]) {
            printf("-1\n");
            continue;
        }
        int cntx = cnt[x];
        if (cntx != cnt[y] && tx2[x] != -1 && tx2[x] != x)
            if (ty[x] != ty2[x])
                ++cntx;
        if (cnt[y] == cntx) {
            int ans = y - x;
            if (tx[x] != -1 && tx[x] <= y && ty[x] == rx) {
                ++ans;
                rx = 3 - rx;
            }
            if (tx2[y] != -1 && tx2[y] >= x && ty2[y] == ry) {
                ++ans;
                ry = 3 - ry;
            }
            if (rx != ry)
                ++ans;
            printf("%d\n", ans);
            continue;
        }
        int ans = cnt[y] - cntx + y - x;
        if (ty[x] == rx)
            ++ans;
        if (ty2[y] == ry)
            ++ans;
        printf("%d\n", ans);
    }
    return 0;
}