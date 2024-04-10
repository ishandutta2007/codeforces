#include <bits/stdc++.h>

const int N = 10;

int n, a[N];
bool found;


void dfs(bool p, int i, int s) {
    if (!found) {
        if (i == n) {
            found = p && s == 0;
        } else {
            dfs(p, i + 1, s);
            dfs(true, i + 1, s + a[i]);
            dfs(true, i + 1, s - a[i]);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", a + i);
            if (a[i] < 0) {
                a[i] *= -1;
            }
        }
        found = false;
        dfs(false, 0, 0);
        puts(found ? "YES" : "NO");
    }
}