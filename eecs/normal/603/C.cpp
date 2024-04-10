#include <bits/stdc++.h>
using namespace std;

int n, K;
// int sg[1010];

int main() {
    scanf("%d %d", &n, &K);
    int s = 0;
    if (!(K & 1)) {
        for (int _ = 1, x; _ <= n; _++) {
            scanf("%d", &x);
            if (x == 1) s ^= 1;
            else if (x == 2) s ^= 2;
            else if (!(x & 1)) s ^= 1;
        }
    } else {
        function<int(int)> sg = [&](int x) {
            if (x == 1) return 1;
            if (x == 2) return 0;
            if (x == 3) return 1;
            if (x == 4) return 2;
            if (x & 1) return 0;
            int y = sg(x - 1), z = sg(x >> 1);
            return y + z == 1 ? 2 : 1;
        };
        for (int _ = 1, x; _ <= n; _++) {
            scanf("%d", &x), s ^= sg(x);
        }
    }
    printf("%s\n", s ? "Kevin" : "Nicky");
    // K = 1;
    // int lst = 0;
    // for (int i = 1; i <= 500; i++) {
    //     unordered_set<int> S;
    //     S.insert(sg[i - 1]);
    //     if (!(i & 1)) {
    //         if (K & 1) S.insert(sg[i >> 1]);
    //         else S.insert(0);
    //     }
    //     while (S.count(sg[i])) sg[i]++;
    //     printf("%d,", sg[i]);
    // }
    return 0;
}