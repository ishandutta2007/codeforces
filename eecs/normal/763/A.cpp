#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, all, c[maxn], cnt[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j : G[i]) if (c[i] ^ c[j]) {
            cnt[i]++, cnt[j]++, all++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == all) printf("YES\n%d\n", i), exit(0);
    }
    puts("NO");
    return 0;
}