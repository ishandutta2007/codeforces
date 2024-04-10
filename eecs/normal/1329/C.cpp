#include <bits/stdc++.h>
using namespace std;

const int maxn = 2100000;
int T, h, g, a[maxn], pos[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &h, &g);
        int n = (1 << h) - 1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), pos[i] = i;
        }
        function<void(int)> F = [&](int x) {
            int ls = x << 1, rs = x << 1 | 1;
            if (ls > n || !a[ls] && !a[rs]) { a[x] = 0; return; }
            if (a[ls] > a[rs]) a[x] = a[ls], F(ls);
            else a[x] = a[rs], F(rs);
        };
        function<int(int)> G = [&](int x) {
            int ls = x << 1, rs = x << 1 | 1;
            if (ls > n || !a[ls] && !a[rs]) return x;
            if (a[ls] > a[rs]) return G(ls);
            else return G(rs);
        };
        vector<int> V;
        function<void(int)> solve = [&](int x) {
            if ((int)log2(x) >= g) return;
            int ls = x << 1, rs = x << 1 | 1;
            while ((int)log2(G(x)) >= g) F(x), V.push_back(x);
            solve(ls), solve(rs);
        };
        solve(1);
        printf("%lld\n", accumulate(a + 1, a + (1 << g), 0LL));
        for (int x : V) printf("%d ", x);
        printf("\n");
    }
    return 0;
}