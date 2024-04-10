#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int T, n, a[maxn];
vector<int> V[maxn];
bool used[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(used, used + n + 1, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] == 1) {
                V[i] = V[i - 1], V[i].push_back(1);
            } else {
                V[i] = V[i - 1];
                while (V[i].back() != a[i] - 1) V[i].pop_back();
                V[i].back()++;
            }
            for (int j = 0; j < V[i].size(); j++) {
                if (j) putchar('.');
                printf("%d", V[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}