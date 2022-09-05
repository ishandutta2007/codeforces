#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, B = 450;
int n, m, x[maxn], y[maxn], sum[maxn], ans[maxn], lst[maxn], coef[500][500];
vector<int> V[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    for (int i = 1, op, k; i <= m; i++) {
        scanf("%d %d", &op, &k);
        if (op == 1) {
            if (x[k] + y[k] <= B) {
                lst[k] = i;
                for (int j = i + x[k]; j < i + x[k] + y[k]; j++) {
                    coef[x[k] + y[k]][j % (x[k] + y[k])]++;
                }
            } else {
                V[k].push_back(i);
            }
        } else {
            if (x[k] + y[k] <= B) {
                for (int j = lst[k] + x[k]; j < lst[k] + x[k] + y[k]; j++) {
                    coef[x[k] + y[k]][j % (x[k] + y[k])]--;
                }
            } else {
                V[k].push_back(i);
            }
        }
        for (int j = 1; j <= B; j++) {
            ans[i] += coef[j][i % j];
        }
    }
    for (int i = 1; i <= n; i++) if (!V[i].empty()) {
        for (int j = 0; j < V[i].size(); j += 2) {
            int nxt = j + 1 < V[i].size() ? V[i][j + 1] - 1 : m;
            for (int cur = V[i][j], op = 0; cur <= nxt; op ^= 1) {
                if (!op) cur += x[i];
                else sum[cur]++, sum[min(nxt + 1, cur + y[i])]--, cur += y[i];
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        sum[i] += sum[i - 1];
        printf("%d\n", sum[i] + ans[i]);
    }
    return 0;
}