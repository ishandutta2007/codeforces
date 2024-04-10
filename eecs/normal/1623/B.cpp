#include <bits/stdc++.h>
using namespace std;

int T, n;
set<pair<int, int>> S;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        S.clear();
        for (int i = 1, l, r; i <= n; i++) {
            scanf("%d %d", &l, &r), S.emplace(l, r);
        }
        queue<pair<int, int>> Q;
        Q.emplace(1, n);
        while (!Q.empty()) {
            auto p = Q.front(); Q.pop();
            for (int i = p.first; i <= p.second; i++) {
                if ((i == p.first || S.count({p.first, i - 1})) &&
                    (i == p.second || S.count({i + 1, p.second}))) {
                    printf("%d %d %d\n", p.first, p.second, i);
                    if (i > p.first) Q.emplace(p.first, i - 1);
                    if (i < p.second) Q.emplace(i + 1, p.second);
                    break;
                }
            }
        }
    }
    return 0;
}