#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010;
int n, K, V, a[maxn], pre[maxn][maxn];
bool f[maxn][maxn];

int main() {
    scanf("%d %d %d", &n, &K, &V);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    f[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < K; j++) if (f[i][j]) {
            f[i + 1][j] = 1, pre[i + 1][j] = j;
            int v = (a[i + 1] + j) % K;
            f[i + 1][v] = 1, pre[i + 1][v] = j;
        }
    }
    if (accumulate(a + 1, a + n + 1, 0) < V || !f[n][V % K]) {
        puts("NO"), exit(0);
    }
    puts("YES");
    vector<int> S, T;
    for (int i = n, j = V % K; i; j = pre[i--][j]) {
        if (j ^ pre[i][j]) S.push_back(i);
        else T.push_back(i);
    }
    for (int i : S) if (i ^ S[0] && a[i]) {
        a[S[0]] += a[i];
        printf("%d %d %d\n", (a[i] + K - 1) / K, i, S[0]);
    }
    for (int i : T) if (i ^ T[0] && a[i]) {
        a[T[0]] += a[i];
        printf("%d %d %d\n", (a[i] + K - 1) / K, i, T[0]);
    }
    if (!V) exit(0);
    if (S.empty() || a[S[0]] < V) {
        printf("%d %d %d\n", (V - (S.empty() ? 0 : a[S[0]])) / K, T[0], S.empty() ? 1 : S[0]);
    } else if (a[S[0]] > V) {
        printf("%d %d %d\n", (a[S[0]] - V) / K, S[0], T.empty() ? 1 : T[0]);
    }
    return 0;
}