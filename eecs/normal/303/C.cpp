#include <bits/stdc++.h>
using namespace std;

int n, K, cnt, a[5010], vis[1000010], head[1000010];
vector<int> all, V[1000010];
struct edge { int k, nxt; } e[13000000];

int main() {
    scanf("%d %d", &n, &K);
    // mt19937 rnd(time(0));
    // n = 2000, K = 4;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        // a[i] = rnd() % 1000000 + 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int v = abs(a[i] - a[j]);
            e[++cnt] = (edge){i, head[v]}, head[v] = cnt;
        }
    }
    for (int i = 1; ; i++) {
        int sz = 0;
        for (int j = 0; j <= 1000000 && sz <= K; j += i) {
            for (int $ = head[j]; $; $ = e[$].nxt) {
                int k = e[$].k;
                if (vis[k] ^ i) sz++, vis[k] = i;
                if (sz > K) break;
            }
        }
        if (sz <= K) printf("%d\n", i), exit(0);
    }
    return 0;
}