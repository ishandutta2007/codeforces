#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, p[maxn], f[maxn], mx[maxn], sec[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n + 1; i++) {
        scanf("%d", &p[i]);
        for (int v = i; v > 1; v = p[v]) {
            if (f[v] >= max(mx[v], sec[v] + 1)) break;
            f[v] = max(mx[v], sec[v] + 1);
            if (f[v] > mx[p[v]]) sec[p[v]] = mx[p[v]], mx[p[v]] = f[v];
            else if (f[v] > sec[p[v]]) sec[p[v]] = f[v];
        }
        printf("%d ", mx[1]);
    }
    return 0;
}