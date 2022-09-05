#include <bits/stdc++.h>
using namespace std;

pair<int, int> p1[4], p2[4];

int main() {
    for (int i = 0; i < 4; i++) {
        scanf("%d %d", &p1[i].first, &p1[i].second);
    }
    for (int i = 0, foo, bar; i < 4; i++) {
        scanf("%d %d", &foo, &bar);
        p2[i].first = foo + bar, p2[i].second = foo - bar;
    }
    int xl = min({p1[0].first, p1[1].first, p1[2].first, p1[3].first});
    int xr = max({p1[0].first, p1[1].first, p1[2].first, p1[3].first});
    int yl = min({p1[0].second, p1[1].second, p1[2].second, p1[3].second});
    int yr = max({p1[0].second, p1[1].second, p1[2].second, p1[3].second});
    int _xl = min({p2[0].first, p2[1].first, p2[2].first, p2[3].first});
    int _xr = max({p2[0].first, p2[1].first, p2[2].first, p2[3].first});
    int _yl = min({p2[0].second, p2[1].second, p2[2].second, p2[3].second});
    int _yr = max({p2[0].second, p2[1].second, p2[2].second, p2[3].second});
    for (int x = -100; x <= 100; x++) {
        for (int y = -100; y <= 100; y++) {
            bool f1 = x >= xl && x <= xr && y >= yl && y <= yr;
            bool f2 = x + y >= _xl && x + y <= _xr && x - y >= _yl && x - y <= _yr;
            if (f1 && f2) puts("YES"), exit(0);
        }
    }
    puts("NO");
    return 0;
}