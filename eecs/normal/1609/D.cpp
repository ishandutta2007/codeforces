#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, d, fa[maxn], sz[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d %d", &n, &d);
    iota(fa + 1, fa + n + 1, 1);
    fill(sz + 1, sz + n + 1, 1);
    int cnt = 0;
    while (d--) {
        int x, y;
        scanf("%d %d", &x, &y);
        x = find(x), y = find(y);
        if (x == y) cnt++;
        else fa[x] = y, sz[y] += sz[x];
        vector<int> V;
        for (int i = 1; i <= n; i++) {
            if (i == find(i)) V.push_back(sz[i]);
        }
        sort(V.begin(), V.end(), greater<int>());
        int s = 0;
        for (int i = 0; i <= cnt; i++) s += V[i];
        printf("%d\n", s - 1);
    }
    return 0;
}