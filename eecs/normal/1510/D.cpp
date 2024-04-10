#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, d, a[maxn], pre[maxn][10];
double f[maxn][10];

int main() {
    scanf("%d %d", &n, &d);
    memset(f, -0x3f, sizeof(f));
    f[0][1] = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        double x = log(a[i]);
        for (int j = 0; j < 10; j++) {
            if (f[i - 1][j] > f[i][j]) {
                f[i][j] = f[i - 1][j], pre[i][j] = -1;
            }
            int k = j * a[i] % 10;
            if (f[i - 1][j] + x > f[i][k]) {
                f[i][k] = f[i - 1][j] + x, pre[i][k] = j;
            }
        }
    }
    if (f[n][d] < 0) puts("-1"), exit(0);
    vector<int> V;
    function<void(int, int)> print = [&](int i, int j) {
        if (!i) return;
        if (~pre[i][j]) V.push_back(a[i]), print(i - 1, pre[i][j]);
        else print(i - 1, j);
    };
    print(n, d);
    printf("%d\n", V.size());
    for (int x : V) printf("%d ", x);
    return 0;
}