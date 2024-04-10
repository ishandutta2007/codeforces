#include <bits/stdc++.h>
using namespace std;

const int maxn = 85;
int n, l[maxn], r[maxn];
double prob[maxn], f[2][maxn][maxn];
double p1[maxn * 2][maxn], p2[maxn * 2][maxn], p3[maxn * 2][maxn];

int main() {
    scanf("%d", &n);
    // n = 80;
    vector<int> V;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &l[i], &r[i]);
        // l[i] = i, r[i] = 1e9 - i;
        V.push_back(l[i]), V.push_back(r[i]);
    }
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    for (int i = 1; i <= n; i++) {
        l[i] = lower_bound(V.begin(), V.end(), l[i]) - V.begin();
        r[i] = lower_bound(V.begin(), V.end(), r[i]) - V.begin();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < V.size(); j++) {
            p1[j][i] = 1.0 * (V[min(j, r[i])] - V[l[i]]) / (V[r[i]] - V[l[i]]);
            p2[j][i] = 1.0 * (V[j + 1] - V[j]) / (V[r[i]] - V[l[i]]);
            p3[j][i] = 1.0 * (V[r[i]] - V[max(j + 1, l[i])]) / (V[r[i]] - V[l[i]]);
        }
    }
    for (int i = 1; i <= n; i++) {
        memset(prob, 0, sizeof(prob));
        for (int j = l[i]; j < r[i]; j++) {
            int cur = 0, nxt = 1;
            memset(f[cur], 0, sizeof(f[cur])), f[0][0][0] = 1;
            for (int k = 1; k <= n; k++, swap(cur, nxt)) {
                for (int less = 0; less <= k; less++) {
                    for (int eq = 0; less + eq <= k; eq++) f[nxt][less][eq] = 0;
                }
                for (int less = 0; less < k; less++) {
                    for (int eq = 0; less + eq < k; eq++) if (f[cur][less][eq] > 1e-15) {
                        if (i ^ k && j > l[k]) f[nxt][less + 1][eq] += f[cur][less][eq] * p1[j][k];
                        if (j >= l[k] && j < r[k]) f[nxt][less][eq + 1] += f[cur][less][eq] * p2[j][k];
                        if (i ^ k && j + 1 < r[k]) f[nxt][less][eq] += f[cur][less][eq] * p3[j][k];
                    }
                }
            }
            for (int less = 0; less < n; less++) {
                for (int eq = 1; less + eq <= n; eq++) {
                    double x = f[cur][less][eq] / eq;
                    prob[less + 1] += x;
                    prob[less + eq + 1] -= x;
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            printf("%.8f%c", prob[j] += prob[j - 1], " \n"[j == n]);
        }
    }
    return 0;
}