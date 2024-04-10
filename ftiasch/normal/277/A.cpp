#include <cstdio>
#include <cstring>

const int N = 100;

int n, m, parent[N];
bool know[N][N], common[N][N];

int find(int i) {
    if (parent[i] == -1) {
        return i;
    }
    return parent[i] = find(parent[i]);
}

bool merge(int i, int j) {
    if (find(i) != find(j)) {
        parent[find(i)] = find(j);
        return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    bool found = false;
    for (int i = 0, k, x; i < n; ++ i) {
        scanf("%d", &k);
        found |= k > 0;
        while (k --) {
            scanf("%d", &x);
            know[i][-- x] = true;
        }
    }
    memset(parent, -1, sizeof(parent));
    int component = n;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            for (int k = 0; k < m; ++ k) {
                common[i][j] |= know[i][k] && know[j][k];
            }
            if (common[i][j]) {
                component -= merge(i, j);
            }
        }
    }
    if (component == 1) {
        puts("0");
    } else {
        if (found) {
            printf("%d\n", component - 1);
        } else {
            printf("%d\n", component);
        }
    }
    return 0;
}