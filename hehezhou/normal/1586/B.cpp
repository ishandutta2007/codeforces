#include <bits/stdc++.h>
using namespace std;
int t;
int n, m;
struct node {
    int a, b, c;
} a[100010];
int vis[100010];
void rmain() {
    scanf("%d%d", &n, &m);
    memset(vis, 0, sizeof(int[n + 5]));
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        vis[b] = 1;
    }
    int mid = 0;
    for (int i = 1; i <= n; i++) if (vis[i] == 0) mid = i;
    for (int i = 1; i <= n; i++) if (i != mid) printf("%d %d\n", i, mid);
}
int main() {
    scanf("%d", &t);
    while (t--) rmain();
}