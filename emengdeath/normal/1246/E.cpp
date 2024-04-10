#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int N = 16;
int f[1 << 16][2001];
int n, k;
int a[N];
#define update(x, y, xx, yy) if (!f[x][y]) f[x][y] = ((xx + 1) | (yy << 17));
pair<int, int> F(int x) {
    if (x % k == 0) {
        auto u = F(x / k);
        u.first += 1;
        return u;
    }
    return {0, x};
}
int main() {
    scanf("%d %d", &n, &k);
    int all = 0;
    for (int i = 0; i < n; i ++)
        scanf("%d", &a[i]), all += a[i];
    f[0][0] = 1;
    for (int i = 0; i <= (1 << n) - 1; i ++) {
        vector<int> d;
        for (int j = 0; j < n; j ++)
            if (!((i >> j) & 1))
                d.push_back(j);
        for (int j = all; j >= 0; j--)
            if (f[i][j]) {
                if (j % k == 0 && j) {
                    update(i, j / k, i, j);
                }
                for (auto u:d)
                    update(i | (1 << u), j +a[u], i, j);
            }
    }
    if (!f[(1 << n) - 1][1]) {
        puts("NO");
        return 0;
    }
    priority_queue<pair<int, int> > d;
    int x = (1 << n) - 1;
    int y = 1, cnt = 0;
    while (x) {
        int xx = (f[x][y]& ((1 << 17) - 1)) - 1, yy = (f[x][y] >> 17);
        if (xx == x) {
            ++cnt;
        } else {
            d.push({cnt, a[31 - __builtin_clz(xx ^ x)]});
        }
        x = xx, y = yy;
    }
    puts("YES");
    while (d.size() > 1) {
        auto u = d.top();
        d.pop();
        auto v = d.top();
        d.pop();
        printf("%d %d\n", u.second,v.second );
        auto w = F(u.second + v.second);
        w.first = u.first - w.first;
        d.push(w);
    }
    return 0;
}