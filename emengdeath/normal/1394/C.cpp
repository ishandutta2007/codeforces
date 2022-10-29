#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
const int N = 5e5 + 10;
char s[N];
int n;
pair<int, int> a[N];
bool check(int ub, int db, int uy, int dy, int ux, int dx, pair<int, int> a) {
    if (!a.first && !a.second) return 0;
    return dx <= a.first && a.first <= ux && dy <= a.second && a.second <= uy && db + a.first <= a.second && a.second <= ub + a.first;
}
pair<int, pair<int, int> > check(int len) {
    int ub = 1e9, db = -1e9, uy = 1e9, dy = 1, ux = 1e9, dx = -1e9;
    for (int i = 1; i <= n; i ++) {
        ub = min(ub, a[i].second - a[i].first + len);
        db = max(db, a[i].second - a[i].first - len);
        uy = min(uy, a[i].second + len);
        dy = max(dy, a[i].second - len);
        ux = min(ux, a[i].first + len);
        dx = max(dx, a[i].first - len);
    }
    if (check(ub, db, uy, dy, ux, dx, {dx, dy})) return {1, {dx, dy}};
    if (check(ub, db, uy, dy, ux, dx, {ux, uy})) return {1, {ux, uy}};
    if (check(ub, db, uy, dy, ux, dx, {ux, dy})) return {1, {ux, dy}};
    if (check(ub, db, uy, dy, ux, dx, {dx, uy})) return {1, {dx, uy}};
    if (check(ub, db, uy, dy, ux, dx, {dx, dx + ub})) return {1, {dx, dx + ub}};
    if (check(ub, db, uy, dy, ux, dx, {dx, dx + db})) return {1, {dx, dx + db}};
    if (check(ub, db, uy, dy, ux, dx, {ux, ux + ub})) return {1, {ux, ux + ub}};
    if (check(ub, db, uy, dy, ux, dx, {ux, ux + db})) return {1, {ux, ux + db}};
    if (check(ub, db, uy, dy, ux, dx, {dy - db, dy})) return {1, {dy - db, dy}};
    if (check(ub, db, uy, dy, ux, dx, {dy - ub, dy})) return {1, {dy - ub, dy}};
    if (check(ub, db, uy, dy, ux, dx, {uy - db, uy})) return {1, {uy - db, uy}};
    if (check(ub, db, uy, dy, ux, dx, {uy - ub, uy})) return {1, {uy - ub, uy}};
    ub = 1e9, db = -1e9, uy = 1e9, dy = -1e9, ux = 1e9, dx = 1;

    for (int i = 1; i <= n; i ++) {
        ub = min(ub, a[i].second - a[i].first + len);
        db = max(db, a[i].second - a[i].first - len);
        uy = min(uy, a[i].second + len);
        dy = max(dy, a[i].second - len);
        ux = min(ux, a[i].first + len);
        dx = max(dx, a[i].first - len);
    }

    if (check(ub, db, uy, dy, ux, dx, {dx, dy})) return {1, {dx, dy}};
    if (check(ub, db, uy, dy, ux, dx, {ux, uy})) return {1, {ux, uy}};
    if (check(ub, db, uy, dy, ux, dx, {ux, dy})) return {1, {ux, dy}};
    if (check(ub, db, uy, dy, ux, dx, {dx, uy})) return {1, {dx, uy}};
    if (check(ub, db, uy, dy, ux, dx, {dx, dx + ub})) return {1, {dx, dx + ub}};
    if (check(ub, db, uy, dy, ux, dx, {dx, dx + db})) return {1, {dx, dx + db}};
    if (check(ub, db, uy, dy, ux, dx, {ux, ux + ub})) return {1, {ux, ux + ub}};
    if (check(ub, db, uy, dy, ux, dx, {ux, ux + db})) return {1, {ux, ux + db}};
    if (check(ub, db, uy, dy, ux, dx, {dy - db, dy})) return {1, {dy - db, dy}};
    if (check(ub, db, uy, dy, ux, dx, {dy - ub, dy})) return {1, {dy - ub, dy}};
    if (check(ub, db, uy, dy, ux, dx, {uy - db, uy})) return {1, {uy - db, uy}};
    if (check(ub, db, uy, dy, ux, dx, {uy - ub, uy})) return {1, {uy - ub, uy}};
    return {0, {0, 0}};
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++){
        scanf("%s", s);
        int len = strlen(s);
        for (int j = 0; j < len ; j ++)
            if (s[j] == 'B') a[i].first ++;
            else
                a[i].second ++;
    }
    int l = 0, r = 1000000, mid, s = 1000000;
    while (l <= r) {
        if (check(mid = (l + r) / 2).first) s = min(s, mid), r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%d\n", s);
    auto u = check(s);
    int x = 0;
    int y = 0;
    x = u.second.first;
    y = u.second.second;
    for (int i = 1; i <= x; i ++)
        printf("B");
    for (int i = 1; i <= y; i ++)
        printf("N");
    return 0;
}