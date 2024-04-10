#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, tot, a[maxn], b[maxn];
vector<int> V[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), a[i] = n - a[i];
        V[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) if (!V[i].empty()) {
        if (V[i].size() % i) puts("Impossible"), exit(0);
        for (int j = 0; j < V[i].size(); j++) {
            if (!(j % i)) tot++;
            b[V[i][j]] = tot;
        }
    }
    puts("Possible");
    for (int i = 1; i <= n; i++) {
        printf("%d ", b[i]);
    }
    return 0;
}