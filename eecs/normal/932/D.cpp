#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 400010;
int n = 1, q, tot = 1, w[maxn], dep[maxn];
int fa[maxn][19], f[maxn][19], mx[maxn][19];
ll sum[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &q), dep[1] = 1;
    for (int i = 1, lst = 0; i <= q; i++) {
        int op; ll x, y;
        scanf("%d %lld %lld", &op, &x, &y);
        x ^= lst, y ^= lst;
        if (op == 1) {
            w[++n] = y, fa[n][0] = x, mx[n][0] = w[x];
            for (int i = 1; i < 19; i++) {
                fa[n][i] = fa[fa[n][i - 1]][i - 1];
                mx[n][i] = max(mx[n][i - 1], mx[fa[n][i - 1]][i - 1]);
            }
            if (mx[n][18] >= w[n]) {
                int cur = n;
                for (int i = 18; ~i; i--) {
                    if (mx[cur][i] < w[n]) {
                        cur = fa[cur][i];
                    }
                }
                cur = fa[cur][0];
                G[cur].push_back(n);
                sum[n] = sum[cur] + w[n];
                f[n][0] = cur, dep[n] = dep[cur] + 1;
                for (int i = 1; i < 19; i++) {
                    f[n][i] = f[f[n][i - 1]][i - 1];
                }
            } else {
                sum[n] = w[n], dep[n] = 1;
            }
        } else {
            if (y < w[x]) { printf("%d\n", lst = 0); continue; }
            int cur = x;
            for (int i = 18; ~i; i--) {
                if (sum[x] - sum[f[cur][i]] <= y) {
                    cur = f[cur][i];
                }
            }
            printf("%d\n", lst = dep[x] - dep[cur]);
        }
    }
    return 0;
}